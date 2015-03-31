#include <map>
#include <string>
#include "monsterdie.h"
using namespace std; 

enum party_types {Fighter, Cleric, Mage, Thief, Champion, Scroll, Used};




//typedef enum party_types 

class PartyDie
{
 public:
  PartyDie();
  PartyDie(party_types);
  
  void setDie(party_types );
  void toggleTemp();
  
  party_types getDie();
  PartyDie * operator = (const PartyDie &);
  void reroll();
  static map<int, party_types> PartyMap;
  static map<party_types, string> TypeToString;
  static map<party_types, monster_type> Bane;
  static void initPartyMap()
  {
    PartyDie::PartyMap[0] = Fighter;
    PartyDie::PartyMap[1] = Cleric;
    PartyDie::PartyMap[2] = Thief;
    PartyDie::PartyMap[3] = Mage;
    PartyDie::PartyMap[4] = Champion;
    PartyDie::PartyMap[5] = Scroll;
    PartyDie::TypeToString[Fighter] = string("fighter");
    PartyDie::TypeToString[Cleric] = string("cleric");
    PartyDie::TypeToString[Thief] = string("thief");
    PartyDie::TypeToString[Mage] = string("Mage");
    PartyDie::TypeToString[Champion] = string("champion");
    PartyDie::TypeToString[Scroll] = string("scroll");
    PartyDie::Bane[Fighter] = Goblin;
    PartyDie::Bane[Mage] = Slime;
    PartyDie::Bane[Cleric] = Skeleton;
    PartyDie::Bane[Thief] = Chest;
    return;
}
 private:
  party_types myFace;
  bool temporary;
};


