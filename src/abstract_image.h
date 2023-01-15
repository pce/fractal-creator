#ifndef ABSTRACT_IMAGE_H
#define ABSTRACT_IMAGE_H

#include "color.h"
#include <vector>

/**
 * @brief AbstractImage render, implement Color value(x,y)
 */
class AbstractImage
{
public:
  AbstractImage();
  AbstractImage(int width, int height);
  virtual void init() = 0;
  void render();
  void render_to_file();
  void set_width(int width);
  void set_height(int height);
  int get_width();
  int get_height();
  void set_zoom(int zoom);
  int get_zoom();
  std::vector<int> get_pixels();
  
protected:
  /**
   * \brief render implict calls virtual Color value(x,y) to create on the fly 
   * and keep focus on the Algorithm, not the rendering :)
   * 
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
  int _width = 640;
  /** \brief Height in Pixel */
  int _height = 640;
  /** \brief Integer Zoom in Percent */
  int _zoom = 100;

  std::vector<int> pixel_array;
};

#endif