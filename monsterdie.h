#ifndef MONSTERDIE_H
#define MONSTERDIE_H

#include <map>
#include <string>
using namespace std;

enum monster_type {Slime, Skeleton, Goblin, Potion, Chest, Dragon, None};

class MonsterDie{
private:
  monster_type myFace;
  bool has_rerolled;
public:
  MonsterDie();
  MonsterDie(monster_type);
  monster_type getFace();
  void reRoll();
  bool hasReRolled();
  void markReRolled();
  void clearReRolled();
  void setFace(monster_type);
  static map<int, monster_type> mons_map;
  static map<monster_type, string> name_map;
  /*Function has to be called to init this class*/
  static void makeMaps(){
    MonsterDie::mons_map[0] = Slime;
    MonsterDie::mons_map[1] = Skeleton;
    MonsterDie::mons_map[2] = Goblin;
    MonsterDie::mons_map[3] = Potion;
    MonsterDie::mons_map[4] = Chest;
    MonsterDie::mons_map[5] = Dragon;
    MonsterDie::mons_map[6] = None;
    MonsterDie::name_map[Slime] = "Slime";
    MonsterDie::name_map[Skeleton] = "Skeleton";
    MonsterDie::name_map[Goblin] = "Goblin";
    MonsterDie::name_map[Potion] = "Potion";
    MonsterDie::name_map[Chest] = "Chest";
    MonsterDie::name_map[Dragon] = "Dragon";
    MonsterDie::name_map[None] = "None";
    return;
  }
};

#endif
