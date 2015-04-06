#include "itempool.h"

ItemPool::ItemPool(){
}

void ItemPool::addItem(item to_add){
  item_pool.push_back(to_add);
  return;
}

item ItemPool::useItem(int i){
  item a = item_pool[i];
  item_pool.erase(item_pool.begin()+i);
  return a;
}

vector<item> ItemPool::getList(){
  return item_pool;
}

/*stub */
int ItemPool::getScore(){
  return 0;
}
