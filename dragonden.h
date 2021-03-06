#ifndef DRAGONDEN_H
#define DRAGONDEN_H
#include <iostream>
#include <cstdlib>

using namespace std;

/* would like to add an operator to this class */
class DragonDen {

 private:
  int num_den;

 public:
  static const int max_dragon;
  DragonDen();
  void clearDen();
  void incrementDen();
  void addToDen(int);
  void fillDen();
  int getCount();
  bool full();
};
#endif
