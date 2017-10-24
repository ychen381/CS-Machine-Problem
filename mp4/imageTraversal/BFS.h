
#ifndef BFS_H
#define BFS_H

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include<vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;
using namespace std;

/**
 * A breadth-first ImageTraversal.
 */
class BFS : public ImageTraversal {
public:
  BFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;
  bool isvisit(Point p);
  double gettolerance() const;
  HSLAPixel startPixel();
  HSLAPixel currPixel(Point p) const;
private:
  PNG png_;
  Point start_;
  double t;
  queue<Point> q;
  vector<bool> visit;
};

#endif
