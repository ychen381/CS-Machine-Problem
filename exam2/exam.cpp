// Your code here!
#include <iostream>
#include<cmath>
#include"exam.h"
#include"matrix.h"
using namespace exam;
using namespace std;

  Matrix exam:: flip_rows(const Matrix &m){
  Matrix n(m.get_num_rows(),m.get_num_columns());
  n=m;
  int i=0;
  if(n.get_num_rows()==1){
    return n;
  }
  if (n.get_num_rows()%2==0){
  for (int x=0;x<n.get_num_rows();x++){
    for(int y=0;y<n.get_num_columns();y++){
      if(i%2==0){
      n.set_coord(x,y,m.get_coord(x+1,y+1));}
      else{
        n.set_coord(x,y,m.get_coord(x-1,y-1));}
        i++;
      }
    }
  }
  for (int x=0;x<n.get_num_rows()-1;x++){
      for(int y=0;y<n.get_num_columns();y++){
        if(i%2==0){
        n.set_coord(x,y,m.get_coord(x+1,y+1));}
        else{
          n.set_coord(x,y,m.get_coord(x-1,y-1));}
          i++;
  }
}
    n.~Matrix();
    return n;

  }
