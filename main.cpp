#include "party.h"
#include "dungeonlevel.h"
#include <cstdlib>
#include <ctime>
//#include "dungeonlevel.h"
using namespace std;
int main(int argv, char **argc){
  PartyDie::initPartyMap();
  MonsterDie::makeMaps();
  //  MonsterDie::makeMaps();
  srand(time(NULL));
  Party P;
  DungeonLevel A(6);
  P.dumpParty();
  A.dumpLevel();
  
}
