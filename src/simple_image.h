#ifndef SIMPLE_IMAGE_H
#define SIMPLE_IMAGE_H

#include "abstract_image.h"

class Pixel {
 public:
  int x;
  int y;
  int c;
};

class SimpleImage : AbstractImage {
 public:
  Color value(int x, int y) override;
  std::vector<Pixel> calculate();
};

#endif