#include "Image.h"

using namespace cs225;

int main() {
  Image alma;

  alma.readFromFile("alma.png");
  alma.lighten(0.2);
  alma.writeToFile("lighten.png");

  alma.readFromFile("alma.png");
  alma.saturate(0.2);
  alma.writeToFile("saturate.png");

  alma.readFromFile("alma.png");
  alma.scale(2);
  alma.writeToFile("scale2x.png");


  alma.readFromFile("alma.png");
  alma.scale(0.4);
  alma.writeToFile("scale0.5x.png");

  alma.readFromFile("alma.png");
  alma.scale(400,400);
  alma.writeToFile("scale.png");
  return 0;
}
