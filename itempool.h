#ifndef ITEMPOOL_H
#define ITEMPOOL_H


#include "item.h"
#include <vector>
#include <map>


using namespace std;

class ItemPool {

 private:
  vector<item> item_pool;
 public:
  ItemPool();
  void addItem(item);
  item useItem(int);
  /*pass by value (hopefully)*/
  vector<item> getList();
  int getScore();
};
#endif
