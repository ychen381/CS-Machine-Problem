#include <iostream>
#include <string>
#include <algorithm>
#include "HSLAPixel.h"
using namespace std;

namespace cs225{
  HSLAPixel::HSLAPixel(){
    a=1.0;
    h=0.0;
    s=0.0;
    l=0.0;
  }

  HSLAPixel::HSLAPixel(double hue,double saturation,double luminance){
    a=1.0;
    h=hue;
    s=saturation;
    l=luminance;

  }

  HSLAPixel::HSLAPixel(double hue,double saturation,double luminance,double alpha){
    a=alpha;
    h=hue;
    s=saturation;
    l=luminance;
  }





}
