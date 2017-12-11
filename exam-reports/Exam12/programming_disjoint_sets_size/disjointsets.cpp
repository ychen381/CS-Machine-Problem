#include "disjointsets.h"
using std::vector;

/**
 * Joins the set containing a and the set containing b.
 *
 * Should use union-by-size. In case of a tie, proceed as if the set containing
 * a has larger size than the set containing b.
 */
void DisjointSets::unionBySize(int a, int b) {
  // TODO: implement this function


  int root_a=find(a);
  int root_b=find(b);
  if(root_a!=root_b){
  int newSize=_data[root_a]+_data[root_b];
  if(_data[root_a]<=_data[root_b]){
    _data[root_b]=root_a;
    _data[root_a]=newSize;
  }
  else{
    _data[root_a]=root_b;
    _data[root_b]=newSize;
  }}

}

/**
 * Finds the representative element of the set containing elem. Should compress
 * paths.
 */
int DisjointSets::find(int elem) {
  // TODO: modify this function to implement path compression
  if (_data[elem] < 0) {
    return elem;
  }
  return _data[elem]=find(_data[elem]);
}


/*************************************
 * PROVIDED CODE - no need to modify *
 *************************************/
void DisjointSets::makeSets(int num) {
  for (; num > 0; num--) {
    _data.push_back(-1);
  }
}

int DisjointSets::simpleFind(int elem) const {
  if (_data[elem] < 0) {
    return elem;
  }
  return simpleFind(_data[elem]);
}
