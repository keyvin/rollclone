#include "dragonden.h"

const int DragonDen::max_dragon = 3;
DragonDen::DragonDen(){
  num_den = 0;
}

void DragonDen::clearDen(){
  num_den = 0;
  return;
}

void DragonDen::fillDen(){
  num_den = DragonDen::max_dragon;
}

int DragonDen::getCount(){
  return num_den;
}

bool DragonDen::full(){
  return (num_den == DragonDen::max_dragon);
}
