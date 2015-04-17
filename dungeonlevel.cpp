#include <vector>
#include "dungeonlevel.h"
#include <iostream>

using namespace std;

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

bool DungeonLevel::monsLeft(){
  for (int a=0; a < dice.size(); a++){
    monster_type face = dice[a].getFace();
    if (face==Slime||face==Goblin||face==Skeleton)
      return true;
  }
  return false;
}

void DungeonLevel::dumpLevel(){
  for (int a=0; a < dice.size(); a++){
    cout << a << ". " << MonsterDie::name_map[dice[a].getFace()] << endl;
  }

  return;
}

int DungeonLevel::clearMonsters(){
  int count =0;
  for (int a=0; a < dice.size(); a++){
    monster_type face = dice[a].getFace();
    if (face == Goblin || face == Skeleton || face == Slime){
      remove(a);
      count++;
    }
  }
  return (count);
}

void DungeonLevel::newLevel(int num){
  dice.resize(num);
  reRollAll();
}

bool DungeonLevel::hasReRolled(int pos){
    return dice[pos].hasReRolled();
}

void DungeonLevel::markAndReRolled(int pos){
    dice[pos].reRoll();
    dice[pos].markReRolled();
}

/*make sure to call this upon exiting the scroll phase*/
void DungeonLevel::clearReRolled(){
    for (int a = 0; a < dice.size(); a++){
        dice[a].clearReRolled();
    }
}
