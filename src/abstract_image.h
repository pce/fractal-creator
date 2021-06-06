#ifndef ABSTRACT_IMAGE_H
#define ABSTRACT_IMAGE_H

#include "color.h"

/**
 * @brief AbstractImage render, implement Color value(x,y)
 */
class AbstractImage {
 public:
  AbstractImage();
  AbstractImage(int width, int height);
  void render();
  void set_width(int width);
  void set_height(int height);
  int get_width();
  int get_height();
  void set_zoom(int zoom);
  int get_zoom();

 protected:
  /**
   * \brief render implict calls virtual Color value(x,y) to focus on the
   * Algorithm
   * @param x PixelPos
   * @param y PixelPos
   */
  virtual Color value(int x, int y) = 0;

  /**
   * \brief get a Color value in relation of value and max
   * @param val
   * @param max
   */
  Color long_rainbow(double val, double max);

  /** \brief Width in Pixel */
  int _width = 800;
  /** \brief Height in Pixel */
  int _height = 600;
  /** \brief Integer Zoom in Percent */
  int _zoom = 100;
};

#endif