#ifndef COLOR_H
#define COLOR_H

#include <sstream>
#include <string>

/**
 * \brief Simple RGB Color
 * nice to have: Indexed or Grayscale (Palette)
 */
class Color {
 public:
  Color(int r, int g, int b) : _r(r), _g(g), _b(b) {}
  Color() {}
  Color(std::string hex_color);
  Color(unsigned int hex_color);
  int r();
  int g();
  int b();
  void r(int r);
  void g(int g);
  void b(int b);
  void hex_to_rgb(std::string hex_color);
  void hex_to_rgb(unsigned int hex_val);
  std::string rgb_to_hex();

  unsigned long GetRGB();

  static constexpr unsigned int red() { return 0xff0000; }
  static constexpr unsigned int green() { return 0x00ff00; }
  static constexpr unsigned int yellow() { return 0xffff00; }
  static constexpr unsigned int blue() { return 0x0000ff; }
  static constexpr unsigned int magenta() { return 0xff00ff; }
  static constexpr unsigned int cyan() { return 0x00ffff; }
  static constexpr unsigned int black() { return 0x0000000; }
  static constexpr unsigned int white() { return 0xffffff; }

 private:
  int _r;
  int _g;
  int _b;
};

#endif