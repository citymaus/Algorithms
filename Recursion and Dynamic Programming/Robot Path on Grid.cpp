/*
  Imagine a robot sitting on the upper left comer of an X by Ygrid. The robot can only
  move in two directions: right and down. How many possible paths are there for the
  robot to go from (0, 0) to (X, Y) ?
  FOLLOW UP
  Imagine certain spots are "off limits," such that the robot cannot step on them.
  Design an algorithm to find a path for the robot from the top left to the bottom right.
*/

#include <unordered_map>

bool getPath(int x, int y, ArrayList<Point> path, Hashtable<Point, bool> cache) 
{
  Point p = new Point(x, y);
  if (cache.containsKey(p)) { // Already visited this cell
    return cache.get(p);
  }

  if (x == 0 && y == 0) {
    return true; // found a path
  }

  boolean success = false;
  if (x >= 1 && isFree(x - 1, y)) { // Try right
    success = getPath(x - 1, y, path, cache); // Free! Go right
  }
  if (!success && y >= 1 && isFree(x, y - 1)) { // Try down
    success = getPath(x, y - 1, path, cache); // Free! Go down
  }
  if (success) {
    path.add(p); // Right way! Add to path
  }
  cache.put(p, success); // Cache result

  return success;
}