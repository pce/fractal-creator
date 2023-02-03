#ifndef SIERPINSKY_CARPET_H
#define SIERPINSKY_CARPET_H

#include <vector>

#include "abstract_image.h"

class SierpinskyCarpet : public AbstractImage {
 public:
  SierpinskyCarpet(int width, int height) : AbstractImage(width, height) {}
  /**
   * @brief returns the value of the precalculated pixel array
   * 
   * @param x 
   * @param y 
   * @return Color 
   */
  Color value(int x, int y) override;
  void init() override;
  void calculate();

 private:
  void draw_bg(unsigned int color);
  void draw_rect(int x1, int y1, int x2, int y2);
  void set_color(unsigned int color);
  void draw_carpet(int x, int y, int size);
  void set_pixel(int x, int y);
  unsigned int get_pixel(int x, int y);
  unsigned int _color = 0x55000000;
};

#endif