#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;
using namespace std;

void rotate(std::string inputFile, std::string outputFile) {
    PNG* original=new PNG();
    original->readFromFile(inputFile);
    unsigned width_=original->width();
    unsigned height_=original->height();
    PNG* output=new PNG();
    output->resize(width_,height_);

    for (unsigned x=0;x< width_;x++){
      for(unsigned y=0;y<height_;y++){

        *(output->getPixel(width_-1-x,height_-1-y))=*(original->getPixel(x,y));

      }
    }
    output->writeToFile(outputFile);
    delete original;
    delete output;


    original=NULL;
    output=NULL;



}
