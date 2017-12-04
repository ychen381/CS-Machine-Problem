/* Your code here! */
#ifndef DESTS_H
#define DESTS_H
#include <vector>

class DisjointSets{
public:
  void addelements(int num);
  int find(int elem);
  void setunion(int a, int b);
  int size(int elem);
private:
  std::vector<int> sets;};
#endif/* Your code here! */
