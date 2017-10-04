#include "list.h"

int main() {
  List<int> list;
  for (int i=1;i<9;i++){
    list.insertBack(i);
  }
  list.waterfall();
  list.print(cout);
  return 0;
}
