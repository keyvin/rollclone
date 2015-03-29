#include "dungeondie.h"

const int DungeonDie::max_level = 10;

DungeonDie::DungeonDie(){
  curr_level = 1;
}

int DungeonDie::getLevel(){
  return curr_level;
}

void DungeonDie::incrementLevel(){
  curr_level++;
}

bool  DungeonDie::atMax(){
  return (curr_level == DungeonDie::max_level);
}
