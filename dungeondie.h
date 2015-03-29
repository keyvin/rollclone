
using namespace std;


class DungeonDie {

 private:
  int curr_level;

 public:
  static const int max_level;
  DungeonDie();
  int getLevel();
  void incrementLevel();
  bool atMax();
};
