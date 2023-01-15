#include "simple_image.h"

#include <fstream>
#include <iostream>

void SimpleImage::init()
{
  std::cout << "SimpleImage::init " << std::endl;
  pixel_array.resize(_width * _height + 1);
  pixel_array.reserve(_width * _height + 1);
}

void SimpleImage::set_pixel(int x, int y)
{
  if (x < 0 || y < 0 || x >= _width || y >= _height)
  {
    return;
  }

  try
  {
    pixel_array.at(y * _width + x) = _color;
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << "Exception SimpleImage::set_pixel out_of_range: " << e.what() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception SimpleImage::set_pixel: " << e.what() << std::endl;
  }
  // std::cout << "SimpleImage::set_pixel " << _color << std::endl;
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
  std::cout << "Size : " << pixel_array.size() << std::endl;
  std::cout << "Capacity : " << pixel_array.capacity() << std::endl;
  std::cout << "Max_Size : " << pixel_array.max_size() << std::endl;
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
  draw_rect(10, 10, _width - 10, _height - 10);

  set_color(Color::blue());
  draw_rect(3, 3, _width - 6, _height - 6);
  draw_rect(30, 30, _width - 30, _height - 30);

  // set_color(Color::black());
  // draw_carpet(0, 0, _width);
}

Color SimpleImage::value(int x, int y)
{
  unsigned int rgb_val = get_pixel(x, y);
  Color color{rgb_val};
  return color;
}
