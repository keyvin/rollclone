#include <string>
#include "party.h"
#include "dungeonlevel.h"
#include "dragonden.h"
#include "dungeondie.h"
#include "itempool.h"
//#include "misc.h"
/* phases 
1.a. use scrolls to reroll dice - need to add code to prevent constant rerolling to get all treasures, or champions or something
1.b. Use hero abilities
1.c. Use companions to defeat monsters
2. Loot Phase
2.a open chests - get one treasure per chest
2.b quaff potions to revive dice - this works by setting a potion count. We are in potion phase until we are out of unused dice, or the potion count is 0.
3. Dragon Phase
*/

enum Phase  {Item, PScroll, PPotion, Monster, Loot, Dragon_Phase, Regroup};
using namespace std;
/* this class has a combat rules object that is changed by hero passives. Need to implement this. One place a heirarchy will work out nicely */
class Table {
 private:
  Party my_party;
  DungeonLevel current_level;
  DragonDen den;
  DungeonDie d_die;
  Phase game_phase;
  ItemPool item_pool;
  int potion_count;
  void makeNewLevel(); /*not done*/
  int parseDragonCommand(string); /*not done*/
  int parseReroll(); /*not done*/
  int parseResurrection(); /*done*/
 public:
  Table();
  void dumpTable();
  void parseCommand(string command); /*done*/
  void parseDiceCommand(string); /*done - combat, chests, and potions*/
  void parseItem(string); /*done*/
};
