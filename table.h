#include <string>
#include "party.h"
#include "dungeonlevel.h"
#include "dragonden.h"
#include "dungeondie.h"
//#include "misc.h"
/* phases 
1.a. use scrolls to reroll dice
1.b. Use hero abilities
1.c. Use companions to defeat monsters
2. Loot Phase
2.a open chests - get one treasure per chest
2.b quaff potions to revive dice
3. Dragon Phase
*/

enum Phase  {Monster, Loot, Dragon_Phase, Regroup};
using namespace std;
/* this class has a combat rules object that is changed by hero passives. Need to implement this. One place a heirarchy will work out nicely */
class Table {
 private:
  Party my_party;
  DungeonLevel current_level;
  DragonDen den;
  DungeonDie d_die;
  Phase game_phase;
  
 public:
  Table();
  void dumpTable();
  void parseCommand(string command);
  void parseDiceCommand(string);
};
