#include <vector>
#include "dungeonlevel.h"


const int DungeonLevel::default_size = 6;

void DungeonLevel::reRollAll(){
  for (int a = 0; a < dice.size(); a ++){
    dice[a].reRoll();
  }
  return;
}

DungeonLevel::DungeonLevel(){
  DungeonLevel(DungeonLevel::default_size); 
}

DungeonLevel::DungeonLevel(const int size){
  dice.resize(size);
  reRollAll();
}

void DungeonLevel::remove(const int remove){
  dice.erase(dice.begin()+remove);
}

void DungeonLevel::reRoll(const int to_reroll){
  dice[to_reroll].reRoll();
}

int DungeonLevel::getSize(){
  return dice.size();
}

monster_type DungeonLevel::getFace(const int die){
  return dice[die].getFace();
}


int DungeonLevel::removeType(monster_type torem){
  int count = 0;
  /* will this work????*/
  for (int a=0; a  < dice.size(); a++){
    if (dice[a].getFace() == torem) {
      dice.erase(dice.begin()+a);
      a--; /*stay in same spot, next spot down just moved up, and size decreased by one*/
      count++;
    }
  }
  return count;
}
