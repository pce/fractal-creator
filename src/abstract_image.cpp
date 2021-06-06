#include "abstract_image.h"

#include <complex>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

AbstractImage::AbstractImage() {
  std::cout << "construct AbstractImage" << std::endl;
}
AbstractImage::AbstractImage(int width, int height)
    : _width(width), _height(height) {}

void AbstractImage::set_width(int width) { _width = width; }

void AbstractImage::set_height(int height) { _height = height; }

int AbstractImage::get_width() { return _width; }

int AbstractImage::get_height() { return _height; }

void AbstractImage::set_zoom(int zoom) { _zoom = zoom; }

int AbstractImage::get_zoom() { return _zoom; }

/**
 * \brief Get the incremented filename (function that may belong to FileUtils)
 *
 * \return std::string
 */
std::string get_inc_filename() {
  using std::filesystem::exists;
  using std::filesystem::path;
  int num = 0;
  // std::string get_filename() { return "out"; }
  std::string name = "out-0.ppm";
  path p{name};
  while (exists(p)) {
    name = "out-" + std::to_string(num++) + ".ppm";
    p = name;
  }
  return name;
}

void AbstractImage::render() {
  std::ofstream img{get_inc_filename(), std::ofstream::out};
  if (!img.is_open()) {
    std::cerr << "could not open file"
              << "\n";
    throw std::runtime_error("could not open file");
  }

  img << "P3\n" << _width << " " << _height << " 255\n";

  for (int y = 1; y <= _height; ++y) {
    // std::cerr << "\r" << y * 100 / _height << "% " << std::flush;
    for (int x = 1; x <= _width; ++x) {
      Color color = value(x, y);
      img << color.r() << " " << color.g() << " " << color.b() << "\n";
    }
  }

  img.close();
}

Color AbstractImage::long_rainbow(double val, double max) {
  double ratio = max / val;
  int normalized = int(ratio * 256 * 6);
  int x = normalized % 256;
  int red = 0, grn = 0, blu = 0;

  switch (normalized / 256) {
    case 0:
      red = 255;
      grn = x;
      blu = 0;
      break;  // red
    case 1:
      red = 255 - x;
      grn = 255;
      blu = 0;
      break;  // yellow
    case 2:
      red = 0;
      grn = 255;
      blu = x;
      break;  // green
    case 3:
      red = 0;
      grn = 255 - x;
      blu = 255;
      break;  // cyan
    case 4:
      red = x;
      grn = 0;
      blu = 255;
      break;  // blue
    case 5:
      red = 255;
      grn = 0;
      blu = 255 - x;
      break;  // magenta
  }
  Color color{red, grn, blu};
  return color;
}
