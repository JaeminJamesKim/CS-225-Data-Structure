#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <string>
#include <iostream>
#include <stack>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  mytol=tolerance;
  mypng=png;
  mypoint=start;
home.push(start);

}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
    BFS * iot = new DFS(mypng, mypoint, mytol );
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  Point *temp =  new Point(point.x,point.y);
  Point *tright =  new Point(point.x+1, point.y);
  Point *tbelow =  new Point(point.x, point.y+1);
  Point *tleft =  new Point(point.x-1, point.y);
  Point *tabove =  new Point(point.x, point.y-1);




  if(
  tabove!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y),mypng.getPixel(point.x, point.y-1))){
    home.push(*tabove);
  }
  if(
  tleft!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y),mypng.getPixel(point.x-1, point.y))){
    home.push(*tleft);
  }
  if(
  tbelow!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y),mypng.getPixel(point.x, point.y+1))){
    home.push(*tbelow);
  }
  if(
  tright!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y), mypng.getPixel(point.x+1,point.y))){
    home.push(*tright);
  }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  Point p=home.top();
  home.pop();
  return p;
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
    return empty()? Point(0, 0): home.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  return home.empty();
}
