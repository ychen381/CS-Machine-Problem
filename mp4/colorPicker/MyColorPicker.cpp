#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 */
MyColorPicker::MyColorPicker(HSLAPixel color1,HSLAPixel color2):color1(color1),color2(color2){}
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  if (x%2==0){
  
    return color1;
  }
  else{

  return color2;}
}
