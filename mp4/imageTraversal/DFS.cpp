#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <algorithm>
#include <vector>
#include<iostream>


#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"
using namespace std;
/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
 png_=png;
 start_=start;
 t=tolerance;
 s.push(start);
 for(unsigned int i=0;i<png_.height()*png_.width();i++){
 visit.push_back(false);
  }
}




/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
DFS* startPoint=new DFS(png_,start_,t);

  return ImageTraversal::Iterator(startPoint);
}


/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  DFS* nullpoint=new DFS(png_,Point(-1,-1),t);
  return ImageTraversal::Iterator(nullpoint);
}




/**
 * Adds a Point for the traversal to visit at some point in the future.
 */

HSLAPixel DFS::startPixel() {
  return *png_.getPixel(start_.x,start_.y);
}

HSLAPixel DFS::currPixel(Point p) const{
  return *png_.getPixel(p.x,p.y);
}

double DFS::gettolerance() const{
  return t;
}


void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  if(point.x==4294967295 && point.y==4294967295){
    s.push(Point(-1,-1));
  }
  else{
  visit.at(point.y * png_.width()+point.x)=true;
  if(point.x+1<png_.width()){
  s.push(Point(point.x+1,point.y));}
  if(point.y+1<png_.height()){
  s.push(Point(point.x,point.y+1));}
  if(point.x>0){
  s.push(Point(point.x-1,point.y));
}
  if(point.y>0){
  s.push(Point(point.x,point.y-1));
}}
}





/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point temp=s.top();
  s.pop();

  return temp;
}

bool DFS::isvisit(Point p){
  return visit.at(p.y*png_.width()+p.x);
}


/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */

  return s.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */

  return s.empty();
}
