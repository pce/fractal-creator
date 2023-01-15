#include "simple_image.h"

#include <fstream>
#include <iostream>

void SimpleImage::init()
{
  pixel_array.reserve(_width * _height);
}

void SimpleImage::set_pixel(int x, int y)
{
  if (x < 0 || y < 0 || x >= _width || y >= _height)
  {
    return;
  }
  pixel_array[y * _width + x] = _color;
}

unsigned int SimpleImage::get_pixel(int x, int y)
{
  if (x < 0)
  {
    x = 0;
  }
  if (y < 0)
  {
    y = 0;
  }
  if (x >= _width)
  {
    x = _width - 1;
  }
  if (y >= _height)
  {
    y = _height - 1;
  }
  return pixel_array[y * _width + x];
}

void SimpleImage::draw_bg(unsigned int color)
{
  for (int i = 0; i <= _height * _width; i++)
  {
    pixel_array[i] = color;
  }
  // std::cout << "Size : " << pixel_array.size() << std::endl;
  // std::cout << "Capacity : " << pixel_array.capacity() << std::endl;
  // std::cout << "Max_Size : " << pixel_array.max_size() << std::endl;
}

void SimpleImage::draw_rect(int x1, int y1, int x2, int y2)
{
  int i;
  for (i = x1; i <= x1 + x2; i++)
  {
    set_pixel(i, y1);
    set_pixel(i, y1 + y2);
  }
  for (i = y1; i <= y1 + y2; i++)
  {
    set_pixel(x1, i);
    set_pixel(x1 + x2, i);
  }
}

void SimpleImage::draw_carpet(int x, int y, int size)
{
  if (size < limit)
  {
    return;
  }
  size /= 3;
  for (int i = 0; i < 9; i++)
  {
    if (i == 4)
    {
      draw_rect(x + size, y + size, size, size);
    }
    else
    {
      draw_carpet(x + (i % 3) * size, y + (i / 3) * size, size);
    }
  }
}

void SimpleImage::set_color(unsigned int color) { _color = color; }

void SimpleImage::calculate()
{
  // example
  draw_bg(Color::green());

  set_color(Color::blue());
  draw_rect(3, 3, _width - 6, _height - 6);
  draw_rect(10, 10, _width - 10, _height - 10);
  draw_rect(30, 30, _width - 30, _height - 30);

  // set_color(Color::black());
  // draw_carpet(0, 0, _width);
}

Color SimpleImage::value(int x, int y)
{
  // IDEA calculate -> draw_polygon/rect, for example a SierpinskiCarpet or
  // Pythagoras Tree (as PixelArray) SimpleImage::value returns the value from
  // the precalculation

  // vector[(row * columns) + column] -> `PixelArray::get_value(x, y)`
  // unsigned int rgb_val = pixel_array[(x * y) + y];
  unsigned int rgb_val = get_pixel(x, y);

  Color color{rgb_val};

  // std::cout << "color.rgb_to_hex: " << color.rgb_to_hex() << " from:" <<
  // rgb_val << std::endl; color.hex_to_rgb(rgb_val);

  return color;
}
