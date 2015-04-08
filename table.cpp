

#include <ctype.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include "table.h"
#include "partydie.h"


using namespace std;

map<Phase, string> Table::phase_map;
Table::Table(){
  potion_count = 0;
  return;
}

void Table::dumpTable(){
  return;
}

void Table::parseCommand(string command){
  //use dice
  int error = 0;
  if (game_phase == Item){
    if (command[0]='Q'){
      game_phase = Monster;
    }
    error = parseItem(command);
  }
  if (game_phase == PPotion){
    error = parseResurrection(command);
    if (!error){
      potion_count--;
      if (!potion_count){
	game_phase = Monster;
      }
    }
  }
  else if (game_phase == PScroll){
    if (command[0]='Q'){
      game_phase = Monster;
      return;
    }
    error = parseReroll(command);
  }
  else if (game_phase == Loot || game_phase == Monster) {
    if (game_phase == Loot && command[0] = 'Q'){
      game_phase = Dragon_Phase;
    }
    else if (game_phase == Monster && !current_level.monsLeft()){
      game_phase = Loot;
    }
    else 
      parseDiceCommand(command);
    
  }
  else if (game_phase == Dragon_Phase) {
    if (den.full()){
      error = parseDragonCommand(command);
    }
    else {
      game_phase = Regroup;
    }
  }
  else if (game_phase == Regroup){
    if (goDeeper(command)){
      makeNewLevel();
    }
    else {
      ;
      /*delve over*/
    }
  }
  
       
  return error;
}

int Table::ParseResurrection(string command){
  int ask_for = -1;
  char com;
  sscanf(command.c_str(), "%c%d", &com, &ask_for);
  if (!my_party.resurrect(PartyDie::PartyMap[ask_for])){
    game_phase = Loot;
  }
  return;
}


void Table::parseDiceCommand(string command){
  int pos = 1;
  string read_int;
  int die = -1;
  int mon = -1;
  party_types p_die;
  monster_type m_die;
  if (isdigit(command[1])){
    read_int.append(&command[1]);
    pos++;
  }
  if (isdigit(command[2])){
    read_int.append(&command[2]);
    pos++;
  }
    //Con
  die = atoi(read_int.c_str());
  cout << "Die: " << die << " selected" << endl;
  if (command[pos]=='m'){
    //at most one digit of m dice
    pos++;
    if (isdigit(command[pos])){
      //convert from char to int
      mon = command[pos] - '0';
    }
  }
  if (mon == -1 || die == -1) {
    cout << "error, refactor to return an error code" << endl;
    return;
    /* Which phase are we in ? if in combat then do x, if in loot do y */
  }
  if (game_phase == Monster) {
    /* clean house and take names - use structures */
    p_die = my_party.getPos(die);
    m_die = current_level.getFace(mon);
    /*is this a bane?*/
    if (PartyDie::Bane[p_die] == m_die || p_die == Champion){
      current_level.removeType(m_die);
      my_party.markUsed(die);
    }
    else {
      current_level.remove(mon);
      my_party.markUsed(die);
    }
    if (!current_level.monsLeft()){
      if (current_level.getSize()){
	game_phase = Loot;
      }
      else
	game_phase = Dragon_Phase;
      return;
    }
  }
  
  if (game_phase == Loot){
    party_types p_face;
    /*quaff potions and loot chests code*/
    if (current_level.getFace(mon) == Potion){
      cout << "Should revive dice, might need to make another stage of the game for quaffing potions" << endl;
      /*set dice to selected, remove potions*/
    }
    if (current_level.getFace(mon) == Chest){
      cout << "Get some treasures" << endl;
      p_die = my_party.getPos(die);
      if (p_face == Thief || p_face == Champion){
	/*get all treasures*/
	int num_treas = current_level.removeType(Chest);
	cout << "stub to award "<< num_treas << "." << endl;
      }
      else{
	current_level.remove(mon);
	my_party.markUsed(die);
	cout << "Award one treasure" << endl;
	/*award one treasure*/
      }
      if (current_level.getSize() == 0){
	game_phase = Dragon_Phase;
      }
    }
    else if (current_level.getFace(mon) == Potion){
      /*TODO - if temporary do not allow quaff*/
      my_party.markUsed(die);
      potion_count = current_level.removeType(Potion);
      game_phase = PPotion;
  }
  return;
}

void Table::parseItem(string command){
/*parse the usage of items - add temporary dice to the party, etc.*/
  char t;
  int pos = -1;
  item itm;
  if (game_phase == Item){
    sscanf(command.c_str(), "%c%d", &t, &pos); //this is not the cpp way to handle this.
    if (pos < 0 || pos > item_pool.getSize()){
      cout << "ERROR, item out of bounds" << endl;
      return;
    }
    /*long ass code that handles the logic for item usage*/
    itm = item_pool.useItem(pos);
    switch (itm){
      case VBlade:
	my_party.addTmp(Fighter);
	break;
      case Talisman:
	my_party.addTmp(Cleric);
	break;
      case SPower:
	my_party.addTmp(Mage);
	break;
      case ThvTool:
	my_party.addTmp(Thief);
	break;
      case IScroll:
	my_party.addTmp(Scroll); /*This may not be correct*/
      case RInv:
	den.clearDen();
	break;
      case Elixer:
	game_phase=PPotion;
	potion_count=1;
	break;
      case DBait:
	den.addToDen(current_level.clearMonsters());	
	break;
      case TPortal:
	/*have to set this one up*/
	break;
     }
  }
  return;
}
