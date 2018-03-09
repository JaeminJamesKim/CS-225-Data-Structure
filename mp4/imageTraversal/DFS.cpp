#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <string>
#include <iostream>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
    mytol=tolerance;
    mypng=png;
    mypoint=start;
  home.push(start);

}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  DFS * iot = new DFS(mypng, mypoint, mytol );
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  Point *temp =  new Point(point.x,point.y);
  Point *tright =  new Point(point.x+1, point.y);
  Point *tbelow =  new Point(point.x, point.y+1);
  Point *tleft =  new Point(point.x-1, point.y);
  Point *tabove =  new Point(point.x, point.y-1);

  if(
  tright!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y), mypng.getPixel(point.x+1,point.y))){
    home.push(*tright);
  }
  else if(
  tbelow!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y),mypng.getPixel(point.x, point.y+1))){
    home.push(*tbelow);
  }
  else if(
  tleft!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y),mypng.getPixel(point.x-1, point.y))){
    home.push(*tleft);
  }
  else if(
  tabove!=temp &&
  mytol>ImageTraversal::calculateDelta(mypng.getPixel(point.x,point.y),mypng.getPixel(point.x, point.y-1))){
    home.push(*tabove);
  }




}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point p=home.top();
  home.pop();
  return p;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return empty()? Point(0, 0): home.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return home.empty();
}
