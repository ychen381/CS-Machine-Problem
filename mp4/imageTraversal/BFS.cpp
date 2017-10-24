
#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  png_=png;
  start_=start;
  t=tolerance;
  q.push(start);
  for(unsigned int i=0;i<png_.height()*png_.width();i++){
  visit.push_back(false);
   }

}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  BFS* startPoint=new BFS(png_,start_,t);

    return ImageTraversal::Iterator(startPoint);
}


/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  BFS* nullpoint=new BFS(png_,Point(-1,-1),t);
  return ImageTraversal::Iterator(nullpoint);
}




HSLAPixel BFS::startPixel() {
  return *png_.getPixel(start_.x,start_.y);
}

HSLAPixel BFS::currPixel(Point p) const{
  return *png_.getPixel(p.x,p.y);
}

double BFS::gettolerance() const{
  return t;
}

bool BFS::isvisit(Point p){
  return visit.at(p.y*png_.width()+p.x);
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  if(point.x==4294967295 && point.y==4294967295){
    q.push(Point(-1,-1));
  }
  else{
  visit.at(point.y * png_.width()+point.x)=true;
  if(point.x+1<png_.width()){
  q.push(Point(point.x+1,point.y));
  }
  if(point.y+1<png_.height()){
  q.push(Point(point.x,point.y+1));
  }
  if(point.x>0){
  q.push(Point(point.x-1,point.y));
}
  if(point.y>0){
  q.push(Point(point.x,point.y-1));
  }}





}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  Point temp=q.front();
  q.pop();

  return temp;

}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */

  return q.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */

    return q.empty();
  }
