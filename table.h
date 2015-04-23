#ifndef TABLE_H
#define TABLE_H

#include <string>
#include "party.h"
#include "dungeonlevel.h"
#include "dragonden.h"
#include "dungeondie.h"
#include "itempool.h"
#include <map>
#include <vector>
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

  vector <party_types> against_dragon;   /*keeps track of what we are using against the dragon*/
  Party my_party;
  DungeonLevel current_level;
  DragonDen den;
  DungeonDie d_die;
  Phase game_phase;
  ItemPool item_pool;
  int potion_count;
  void makeNewLevel(); /*not done*/
  int parseDragonCommand(string); /*not done*/
  int parseReroll(string); /*not done*/
  int parseResurrection(string); /*done*/
 public:
  Table(): current_level(1) {potion_count=0;game_phase=Item; item_pool.addRandom(); item_pool.addRandom(); };
  void dumpTable();
  int parseCommand(string); /*done*/
  int parseDiceCommand(string); /*done - combat, chests, and potions*/
  int parseItem(string); /*done*/
  bool goDeeper(string);
  static map<Phase, string> phase_map;
  static void makePhaseMap() {
    phase_map[Item] = "Item";
    phase_map[PScroll] = "Scroll";
    phase_map[PPotion] = "Potion";
    phase_map[Monster] = "Monster";
    phase_map[Loot] = "Loot";
    phase_map[Dragon_Phase] = "Dragon";
    phase_map[Regroup] = "Regroup";
  }
  //enum Phase  {Item, PScroll, PPotion, Monster, Loot, Dragon_Phase, Regroup};
};
#endif

