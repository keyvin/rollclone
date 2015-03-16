#include <string>
#include "party.h"
#include "dungeonlevel.h"
#include "dragonden.h"
#include "dungeondie.h"

using namespace std;
/* this class has a combat rules object that is changed by hero passives. Need to implement this. One place a heirarchy will work out nicely */
class Table {
 private:
  Party my_party();
  DungeonLevel current_level();
  DragonDen den();
  DungeonDie d_die();

 public:
  Table();
  dumpTable();
  parseCommand(string command);
};
