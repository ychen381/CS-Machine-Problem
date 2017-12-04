/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num){
  for (int i=0;i<num;i++){
    sets.push_back(-1);
}
}

int DisjointSets::find(int elem){
  if(sets[elem]<0){
    return elem;}
  return sets[elem]=find(sets[elem]);

}

void DisjointSets::setunion(int a, int b){
  int root_a=find(a);
  int root_b=find(b);

  int newSize=sets[root_a]+sets[root_b];

  if((sets[root_a]<=sets[root_b])){

    sets[root_b]=root_a;
      sets[root_a]=newSize;


  }
  else{

    sets[root_a]=root_b;
    sets[root_b]=newSize;
  }
}


int DisjointSets::size(int elem){
  return sets[find(elem)];

}
