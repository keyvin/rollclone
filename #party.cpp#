#include <iostream>
#include "party.h"

using namespace std;
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

bool Party::resurrect(const party_types &ask_for){
  /* to resurrect, there must be a used non temporary die*/
  for (int a=0; a < party.size(); a++){
    if (!party[a].isTemp() && party[a].getDie() == Used){
      party[a].setDie(ask_for);
      return true;
    }
  }
  return false;
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
void Party::addTmp(const party_types &p_face){
  PartyDie tmp(p_face);
  tmp.toggleTemp();
  party.push_back(tmp);
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

void Party::dumpParty() {
  for (int a = 0; a < party.size(); a++){
    cout << a << ". " << PartyDie::TypeToString[party[a].getDie()] << endl;
  }
  return;
}
      


