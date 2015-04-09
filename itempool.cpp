#include "itempool.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

map<int, item> ItemPool::item_map;
map<item, string> ItemPool::item_name_map;


ItemPool::ItemPool(){
}

void ItemPool::dumpItemPool(){
  for (int a = 0; a< item_pool.size(); a++){
    cout << a << ". " << item_name_map[item_map[a]];
  }
  cout << endl;
  return;
}

void ItemPool::addRandom(){
  item_pool.push_back(item_map[rand()%10]);
  return;
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

int ItemPool::getSize(){
  return item_pool.size();
}
