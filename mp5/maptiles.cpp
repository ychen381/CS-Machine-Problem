/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include <vector>
#include "maptiles.h"
#include "sourceimage.h"
#include "kdtree.h"
#include "cs225/HSLAPixel.h"
using namespace std;
using namespace cs225;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**

     * @todo Implement this function!
     */

     MosaicCanvas* mos=new MosaicCanvas(theSource.getRows(),theSource.getColumns());
     vector<Point<3>> tilepoint;
     map<Point<3>,TileImage> outmap;

     for(unsigned long i=0;i<theTiles.size();i++){
       HSLAPixel temp=theTiles[i].getAverageColor();
       Point<3> push;
       push[0]=(temp.h)/360;
       push[1]=temp.s;
       push[2]=temp.l;
       tilepoint.push_back(push);
       outmap.insert(pair<Point<3>,TileImage>(push,theTiles[i]));
     }
     KDTree<3>* tiletree=new KDTree<3>(tilepoint);

     for(int i=0;i<theSource.getRows();i++){
       for(int j=0; j<theSource.getColumns();j++){
         HSLAPixel color=theSource.getRegionColor(i,j);
         double h=(color.h)/360;
         double s=color.s;
         double l=color.l;
          Point<3> Pcolor;
          Pcolor[0]=h;
          Pcolor[1]=s;
          Pcolor[2]=l;
          Point<3> ret_point=tiletree->findNearestNeighbor(Pcolor);
          mos->setTile(i,j,outmap.find(ret_point)->second);

       }
     }



    return mos;
}
