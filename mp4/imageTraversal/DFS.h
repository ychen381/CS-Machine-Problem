#ifndef DFS_H
#define DFS_H

#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;
using namespace std;

/**
 * A depth-first ImageTraversal.
 */
class DFS : public ImageTraversal {
public:
  DFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;
  bool isvisit(Point p);
  double gettolerance() const;
  HSLAPixel startPixel() ;
  HSLAPixel currPixel(Point p) const;
private:
  PNG png_;
  Point start_;
  double t;
  stack<Point> s;
  vector<bool>  visit;

};

#endif
