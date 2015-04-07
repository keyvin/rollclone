#include "partydie.h"
#include <iostream>


#include <stdlib.h>

using namespace std;

map <int, party_types>PartyDie::PartyMap;
map <party_types, string> PartyDie::TypeToString;
map <party_types, monster_type> PartyDie::Bane;

PartyDie::PartyDie(){
  reroll();
  temporary = false;
}

PartyDie::PartyDie(party_types a){
  setDie(a);
  temporary = false; 
}

bool PartyDie::isTemp(){
  return temporary;
}
void PartyDie::setDie(party_types a)
{
  myFace = a;
  return;
}

party_types PartyDie::getDie()
{
  return myFace;
}

PartyDie * PartyDie::operator =(const PartyDie &other)
{
  myFace = other.myFace;
  return this;
    
}

void PartyDie::toggleTemp(){
  temporary = true;
}

void PartyDie::reroll(){
  myFace = (party_types) PartyDie::PartyMap[rand()%6];
  return;
}
   
