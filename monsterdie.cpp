#include "monsterdie.h"
#include <string>
#include <map>
#include <cstdlib>

/*declare static members*/
map<int, monster_type> MonsterDie::mons_map;
map<monster_type, string> MonsterDie::name_map;

MonsterDie::MonsterDie(){
  myFace = None;
  has_rerolled = false;
}

MonsterDie::MonsterDie(monster_type my){
  myFace = my;
}

monster_type MonsterDie::getFace(){
  return myFace;
}

void MonsterDie::reRoll(){
  myFace = mons_map[rand()%6];
  return;
}

void MonsterDie::setFace(monster_type a){
  myFace = a;
}

bool MonsterDie::hasReRolled(){
    return has_rerolled;
}
void MonsterDie::markReRolled(){
    has_rerolled = true;
return;
}
void MonsterDie::clearReRolled(){
    has_rerolled = false;
}
