#include <vector>
#include "monsterdie.h"
/*This header file lays out the dungeonlevel code. 
  Generating a dungeon level is simple - roll six dice*/


using namespace std;

/*It should have a set number of dice upon creation, allow the reroll of specific dice, the removal of specific dice, etc*/

class DungeonLevel{
 private:
  vector<MonsterDie> dice;
 public:
  DungeonLevel();
  DungeonLevel(const int);
  void reRoll(const int);
  void reRollAll();
  void remove(const int);
  /*removes face and returns type*/
  int removeType(monster_type);
  int getSize();
  bool monsLeft();
  monster_type getFace(const int);
  static const int default_size;
  void dumpLevel();
};
