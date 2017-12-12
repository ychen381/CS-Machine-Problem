/* Your code here! */
#ifndef _MAZE_H
#define _MAZE_H

#include <vector>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace cs225;

class SquareMaze{
public:
    SquareMaze();
    void makeMaze(int width, int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y, int dir, bool exists);
    vector<int> solveMaze();
    PNG* drawMaze() const;
    PNG* drawMazeWithSolution();

private:
    int w;
    int h;
    vector<bool> right;
    vector<bool> down;
    int leave;
};
#endif//maze.h
