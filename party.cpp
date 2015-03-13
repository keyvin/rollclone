#include "party.h"

const int Party::numdie = 6;


//bad code. I should initialize party with a size and then use that rather than a const. This is just lazy to get it to work. 
/* initialize numdie dice */
Party::Party(){
  for (int a = 0; a < numdie; a++){
    party.push_back(PartyDie());
  }
}

/*add range checking*/
void Party::reroll(const int &to_reroll) {
  party[to_reroll].reroll();
}

//returns list of dice to draw
vector <party_types> Party::getArray(){
  vector <party_types> to_ret;
  for (int a = 0; a < numdie + tmpdie; a++){
    to_ret.push_back(party[a].getDie());
  }
  return to_ret;
}

party_types Party::getPos(const int &pos){
  return party[pos].getDie();
}

/*stub for now - must set tmp flag*/
void Party::addItem(const Item &item){
  return;
}

/*clears items that were added*/
void Party::clearTemp(){
  for (int a = numdie; a < tmpdie+numdie; a++){
    party.pop_back();
  }
  tmpdie = 0;
  return;
}

/*misleading name - perhaps markused*/
void Party::markUsed(const int &pos){
  party[pos].setDie(Used);
  return;
}




