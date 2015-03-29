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
  void fillDen();
  int getCount();
  bool full();
};

