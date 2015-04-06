#include <ctype.h>
#include <cstdlib>
#include <string>
#include "table.h"
#include "partydie.h"


using namespace std;

Table::Table(){
  return;
}

void Table::dumpTable(){
  return;
}

void Table::parseCommand(string command){
  //use dice
  if (command[0] == 'd') {
    parseDiceCommand(command);
  }
  //use item

  //use
  
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
  }
  return;
}

void Table::parseItem(string command){
/*parse the usage of items - add temporary dice to the party, etc.*/
return;
}
