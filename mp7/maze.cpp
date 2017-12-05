/* Your code here! */
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <sys/time.h>
#include <time.h>
#include "maze.h"
#include "dsets.h"

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace cs225;

SquareMaze::SquareMaze()
{
    w = 0;
    h = 0;
    right.clear();
    down.clear();
}

void SquareMaze::makeMaze(int width, int height)
{
    right.clear();
    down.clear();

    w = width;
    h = height;
    int size = w*h;
    right = vector<bool>(size, true);
    down = vector<bool>(size, true);

    DisjointSets sets;
    sets.addelements(size);

    int count = 0;
    while (count < size -1){
        for(int i = 0; i < size; i++){

            int ifrandom = rand() % 10 + 1;
            if (ifrandom > 5){
                if ((i+1) % w != 0 && sets.find(i) != sets.find(i+1)){
                    right[i] = false;
                    sets.setunion(i,i+1);
                    count = count + 1;
                }
            }else{
                if (i - h*(w-1) < 0 && sets.find(i) != sets.find(i+w)){
                    down[i] = false;
                    sets.setunion(i, i+w);
                    count = count + 1;
                }
            }

        }
    }
}

bool SquareMaze::canTravel(int x, int y, int dir) const
{
    int place = y*w+x;

    if (x < 0 || y < 0 || x >= w || y >= h) return false;

    if ((dir == 0 && x == w -1) || (dir == 1 && y == h -1) || (dir == 2 && x == 0) || (dir == 3 && y == 0))
        return false;

    if (dir == 0){
        return !right[place];
    }

    if (dir == 1){
        return !down[place];
    }

    if (dir == 2){
        return !right[place-1];
    }

    if (dir == 3){
        return !down[place-w];
    }

    return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
    int place = y*w+x;

    if (dir == 0) right[place] = exists;
    if (dir == 1) down[place] = exists;
}

vector<int> SquareMaze::solveMaze()
{
    int size = w*h;
    vector<int> out;
    vector<int> length(size, -1);
    vector<int> path(size, -1);
    vector<int> parent(size,-1);
    queue<int> route;
    route.push(0);

    while (!route.empty()){
        int place = route.front();
        int x = place % w;
        int y = place / w;

        if (canTravel(x, y, 0)){
            if (length[place + 1] < 0){
                length[place + 1] = length[place] + 1;
                path[place + 1] = 0;
                parent[place + 1] = place;
                route.push(place + 1);
            }
        }

        if (canTravel(x,y,1)){
            if (length[place + w] < 0){
                length[place + w] = length[place] + 1;
                path[place + w] = 1;
                parent[place + w] = place;
                route.push(place + w);
            }
        }

        if (canTravel(x,y,2)){
            if (length[place - 1] < 0){
                length[place - 1] = length[place] + 1;
                path[place - 1] = 2;
                parent[place - 1] = place;
                route.push(place - 1);
            }
        }

        if (canTravel(x,y,3)){
            if (length[place - w] < 0){
                length[place - w] = length[place] + 1;
                path[place - w] = 3;
                parent[place - w] = place;
                route.push(place - w);
            }
        }

        route.pop();
    }

    int shortest = -1;
    int temp = -1;
    for (int i = w*(h-1); i < size; i++){
        if (length[i] > shortest){
            shortest = length[i];
            temp = i;
            exit = i;
        }
    }

    while (temp > 0) {
        out.push_back(path[temp]);
        temp = parent[temp];
    }

    vector<int> output;
    while (!out.empty()){
        output.push_back(out.back());
        out.pop_back();
    }
    return output;
}

PNG* SquareMaze::drawMaze() const
{
    PNG* output = new PNG(10*w+1, 10*h+1);
    int size = w*h;

    for(int x = 10; x < 10*w+1; x++){
        (*output).getPixel(x,0)->h = 0;
        (*output).getPixel(x,0)->s = 0;
        (*output).getPixel(x,0)->l = 0;
    }

    for (int y = 0; y < h*10+1; y++){
        (*output).getPixel(0,y)->h = 0;
        (*output).getPixel(0,y)->s = 0;
        (*output).getPixel(0,y)->l = 0;
    }

    for (int i = 0; i < size; i++){
        int x = i % w;
        int y = i / w ;
        if (right[i]){
            for(int k = 0; k <= 10; k++){
                (*output).getPixel(10*(x+1),y*10+k)->h = 0;
                (*output).getPixel(10*(x+1),y*10+k)->s = 0;
                (*output).getPixel(10*(x+1),y*10+k)->l= 0;
            }
        }

        if (down[i]){
            for(int k = 0; k <= 10; k++){
                (*output).getPixel(10*x+k,(y+1)*10)->h = 0;
                (*output).getPixel(10*x+k,(y+1)*10)->s = 0;
                (*output).getPixel(10*x+k,(y+1)*10)->l = 0;
            }
        }
    }
    return output;
}

PNG* SquareMaze::drawMazeWithSolution()
{
    PNG* output = drawMaze();
    vector<int> route = solveMaze();
    int x = 5;
    int y = 5;

    for(unsigned long i = 0; i < route.size(); i++){
        if(route[i] == 0){
            for (int k = 0; k <= 10; k++){
                (*output).getPixel(x+k,y)->h= 255;
                (*output).getPixel(x+k,y)->s = 0;
                (*output).getPixel(x+k,y)->l= 0;
            }
            x = x + 10;
        }

        if(route[i] == 1){
            for (int k = 0; k <= 10; k++){
                (*output).getPixel(x,y+k)->h = 255;
                (*output).getPixel(x,y+k)->s = 0;
                (*output).getPixel(x,y+k)->l = 0;
            }
            y  = y + 10;
        }

        if(route[i] == 2){
            for (int k = 0; k <= 10; k++){
                (*output).getPixel(x-k,y)->h= 255;
                (*output).getPixel(x-k,y)->s = 0;
                (*output).getPixel(x-k,y)->l = 0;
            }
            x = x - 10;
        }

        if(route[i] == 3){
            for (int k = 0; k <= 10; k++){
                (*output).getPixel(x,y-k)->h= 255;
                (*output).getPixel(x,y-k)->s = 0;
                (*output).getPixel(x,y-k)->l = 0;
            }
            y  = y - 10;
        }
    }

    int exitX = exit % w;
    int exitY = exit / w;
    for(int k = 1; k <= 9; k++)
    {
        (*output).getPixel(exitX*10+k, (exitY+1)*10)->h= 255;
        (*output).getPixel(exitX*10+k, (exitY+1)*10)->s = 255;
        (*output).getPixel(exitX*10+k, (exitY+1)*10)->l = 255;
    }

    return output;
}
