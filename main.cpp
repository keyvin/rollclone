#include "party.h"
#include "dungeonlevel.h"
#include "table.h"
#include <cstdlib>
#include <ctime>
//#include "dungeonlevel.h"
using namespace std;


int main(int argv, char **argc){
  PartyDie::initPartyMap();
  MonsterDie::makeMaps();
  Table::makePhaseMaps();
  Table table;
  string command;
  //  MonsterDie::makeMaps();
  srand(time(NULL));
  Party P;
  DungeonLevel A(6);


  
}
