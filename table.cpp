#include <ctype.h>
#include <cstdlib>
#include <string>

using namespace std;

Table::Table(){
  return;
}

void Table::dumpTable(){
  return;
}

void Table::parseCommand(string command){
  int pos = 1;
  string read_int();
  int die = 0;
  //use dice
  if (command[0] == 'd') {
    if (isdigit(command[1])){
      read_int += command[1];
      pos++;
    }
    if (isdigit(command[2])){
      read_int += command[2];
      pos++;
    }
    //Con
    die = atoi(read_int.c_str());
    cout << "Die: " << die << " selected" << endl;

  }
  
  return;
}
