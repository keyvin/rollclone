#include <ctype.h>
#include <cstdlib>
#include <string>
#include "table.h"

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
    
  }
  
  return;
}

void Table::parseDiceCommand(string command){
  int pos = 1;
  string read_int();
  int die = -1;
  int mon = -1;
  party_type p_die;
  monster_type m_die;
  if (isdigit(command[1])){
    read_int += command[1];
    pos++;
  }
  if (isdigit(command[2])){
    read_int += command[2];
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
      game_phase = Loot;
      return;
    }
  }
  if (game_phase == Loot){
    /*quaff potions and loot chests code*/
  }
  return;
}
