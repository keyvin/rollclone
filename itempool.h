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
  void addRandom();
  void dumpItemPool();
  item useItem(int);
  /*pass by value (hopefully)*/
  vector<item> getList();
  int getScore();
  int getSize();
  static map<int, item> item_map;
  static map<item, string> item_name_map;
  static void makeItemMap(){
    ItemPool::item_map[0] = VBlade;     
    ItemPool::item_map[1] = Talisman;
    ItemPool::item_map[2] = SPower;
    ItemPool::item_map[3] = ThvTool;
    ItemPool::item_map[4] = IScroll;
    ItemPool::item_map[5] = RInv;
    ItemPool::item_map[6] = Scale;
    ItemPool::item_map[7] = Elixir;
    ItemPool::item_map[8] = DBait;
    ItemPool::item_map[9] = TPortal;
    ItemPool::item_name_map[VBlade] = "VBlade";
    ItemPool::item_name_map[Talisman] = "Talisman";
    ItemPool::item_name_map[SPower] = "Spower";
    ItemPool::item_name_map[ThvTool] = "ThvTool";
    ItemPool::item_name_map[IScroll] = "IScroll";
    ItemPool::item_name_map[RInv] = "RInv";
    ItemPool::item_name_map[Scale] = "Scale";
    ItemPool::item_name_map[Elixir] = "Elixer";
    ItemPool::item_name_map[DBait] = "DBait";
    ItemPool::item_name_map[TPortal] = "TPortal";
  };
};
#endif
