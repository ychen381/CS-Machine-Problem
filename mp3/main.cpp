#include "list.h"

int main() {
  List<int> list1;

    list1.insertBack(5);
    list1.insertBack(1);
    list1.insertBack(8);
  
  list1.print(cout);

  list1.sort();
  list1.print(cout);

  return 0;
}
