

#include <ctype.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include "partydie.h"
#include "table.h"



using namespace std;

map<Phase, string> Table::phase_map;

/*Table::Table(){
  potion_count = 0;
  return;
  }*/

void Table::dumpTable(){
  cout << "Party" << endl;
  my_party.dumpParty();
  cout << "Monsters" << endl;
  current_level.dumpLevel();
  cout << "Items" << endl;
  item_pool.dumpItemPool();
  cout << "Dragon den has: " << den.getCount() << endl;
  cout << "Phase: " << phase_map[game_phase] << endl;

  return;
}

int Table::parseCommand(string command){
  //use dice
  int error = 0;
  if (game_phase == Item){
    if (command[0]=='Q'){
      game_phase = Monster;
    }
    error = parseItem(command);
  }
  else if (game_phase == PPotion){
    error = parseResurrection(command);
    if (!error){
      potion_count--;
      if (!potion_count){
	game_phase = Monster;
      }
    }
  }
  else if (game_phase == PScroll){
    if (command[0]=='Q'){
      game_phase = Monster;
      return 0 ;
    }
    error = parseReroll(command);
  }
  else if (game_phase == Loot || game_phase == Monster) {
    if (game_phase == Loot && command[0] == 'Q'){
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
  /*if there are no monsters, skip to loot*/


  /* if there is no dragon, skip to regroup*/
  if (game_phase == Monster){
    if (!current_level.monsLeft()){
        game_phase = Loot;
    }
  }

  if (game_phase == Dragon_Phase){
    if (!den.full()){
        game_phase = Regroup;
    }
  }

  return error;
}

int Table::parseResurrection(string command){
  int ask_for = -1;
  char com;
  sscanf(command.c_str(), "%c%d", &com, &ask_for);
  if (!my_party.resurrect(PartyDie::PartyMap[ask_for])){
    game_phase = Loot;
  }
  return 0;
}


int Table::parseDiceCommand(string command){
  int pos = 1;
  string read_int;
  char p;
  int die = -1;
  int mon = -1;
  party_types p_die;
  monster_type m_die;
  if (command[0] == 'S'){
    sscanf(command.c_str(), "%c%d", &p, &die);
    if (my_party.getPos(die) == Scroll){
        game_phase = PScroll;
        my_party.markUsed(die);
    }
    else
    {
        cout << "Not a scroll" << endl;
    }
    return 0;
  }

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
  if (command[pos]=='M'){
    //at most one digit of m dice
    pos++;
    if (isdigit(command[pos])){
      //convert from char to int
      mon = command[pos] - '0';
    }
  }
  if (mon == -1 || die == -1) {
    cout << "error, refactor to return an error code" << endl;
    return 0;
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
      return 0;
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
	for (int a = 0; a < num_treas; a++){
	  item_pool.addRandom();
	}
      }
      else{
	current_level.remove(mon);
	my_party.markUsed(die);
	cout << "Award one treasure" << endl;
	item_pool.addRandom();
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
  }
  return 0;
}

int Table::parseItem(string command){
/*parse the usage of items - add temporary dice to the party, etc.*/
  char t;
  int pos = -1;
  item itm;

  if (game_phase == Item){
    sscanf(command.c_str(), "%c%d", &t, &pos); //this is not the cpp way to handle this.
    if (pos < 0 || pos > item_pool.getSize()){
      cout << "ERROR, item out of bounds" << endl;
      return 0;
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
	my_party.addTmp(Scroll);
      case RInv:
	den.clearDen();
	break;
      case Elixir:
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
  return 0;
}

//TODO - KEEP FROM REROLLING TEMPS
int Table::parseReroll(string command){
  char a;
  int die = -1;
  sscanf(command.c_str(), "%c%d", &a, &die);
  if (command[0] == 'Q'){
    current_level.clearReRolled();
    my_party.clearReRolled();
    game_phase = Monster;
  }
  if (die < 0){
    cout << "Invalid die" << endl;
    return 300;
  }
  if (command[0] == 'M'){
    if (!current_level.hasReRolled(die)){
        current_level.markAndReRolled(die);
    }
    else {
        cout << "already rerolled" << endl;
        return 301;
    }
  }
  if (command[0] == 'D') {
    if (!my_party.hasReRolled(die) && my_party.getPos(die) !=Used && !my_party.isTemp(die) ){
        my_party.markReRolled(die);
        my_party.reRoll(die);
    }
    else {
        cout << "already rerolled, used, or is temp" << endl;
        return 302;
    }
  }

  return 0;
}

/*TODO - if not enough dice, force lose*/
int Table::parseDragonCommand(string command){
  char a;
  int sel_die = -1;
  sscanf(command.c_str(), "%c%d", &a, &sel_die);

  if (sel_die > 0){
    party_types face = my_party.getPos(sel_die);
    if (face == Fighter || face == Champion || face == Mage || face == Cleric || face == Thief){
      for (int a =0; a < against_dragon.size(); a++){ /* Might be a candidate for refactor to dragon den*/
        if (face == against_dragon[a]) {
        cout << "Die face already used" << endl;
        return 0; /*return an error code indicating this is already used*/
        }
      }
      against_dragon.push_back(face);
      my_party.markUsed(sel_die);
      if (against_dragon.size() == 3){
        cout << "Dragon slayed, treasure awarded - TODO add experience point";
        item_pool.addRandom();
        against_dragon.erase(against_dragon.begin(), against_dragon.end());
        den.clearDen();
        game_phase = Regroup;
      }
    }
  }
  else {
    cout << "Invalid Die";
    return 0;  /*return error saying must pick a valid face*/
  }
  return 0;
}

bool Table::goDeeper(string command){
  if (command[0] == 'Y')
    return true;
  else
    return false;
}

void Table::makeNewLevel(){
  int num_dragons = 0;
  int max_dice = 0;
  int tmp = 0;
  /*calculate how many dice are available. Hard to figure out right now*/
  max_dice = d_die.getLevel();
  if (max_dice > 6){
    max_dice = 6;
  }
  if (den.getCount() + max_dice > 6){
    tmp = 6 - (den.getCount() + max_dice);
    max_dice = 6 + tmp;
  }
  current_level.newLevel(max_dice);
  d_die.incrementLevel();
  num_dragons = current_level.removeType(Dragon);
  den.addToDen(num_dragons);
  game_phase = Item;
  return;
}

