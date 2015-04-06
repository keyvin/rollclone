#ifndef PARTY_H
#define PARTY_H
#include "partydie.h"
#include <vector>


/*stub definition*/
//typedef int Item;

class Party {
 private:
  vector<PartyDie> party;
  static const int numdie;
  int tmpdie;
 public:

  Party(); /*new party*/
  void reroll(const int&);
  vector <party_types> getArray();
  party_types getPos(const int&);
  void addTmp(const party_types &);

  void clearTemp();
  void markUsed(const int&);
  void dumpParty();
};
#endif
