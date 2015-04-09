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
  Table::makePhaseMap();
  Table table;
  string command;
  bool q = false;
  //  MonsterDie::makeMaps();
  srand(time(NULL));
  Party P;
  DungeonLevel A(6);
  A.dumpLevel();
  while (1){
    table.dumpTable();
    cin >> command;
    
    if (command == "QUIT"){
      cout << "exiting" << endl;
      break;
    }
    else
      table.parseCommand(command);
  }


  
}
