#include "color.h"

Color::Color(std::string hex_color) { hex_to_rgb(hex_color); }

Color::Color(unsigned int hex_color) { hex_to_rgb(hex_color); }

void Color::hex_to_rgb(std::string hex_color) {
  unsigned int hex_val = std::stoul(hex_color, nullptr, 16);
  hex_to_rgb(hex_val);
}

/**
 * \brief wip, this is a setter ...
 *
 * \param hex_val
 */
void Color::hex_to_rgb(unsigned int hex_val) {
  _r = ((hex_val >> 16) & 0xff);
  _g = ((hex_val >> 8) & 0xff);
  _b = ((hex_val)&0xff);
}

std::string Color::rgb_to_hex() {
  std::stringstream ss;
  // ss << "#";
  ss << std::hex << (_r << 16 | _g << 8 | _b);
  return ss.str();
}

int Color::r() { return _r; }

int Color::g() { return _g; }

int Color::b() { return _b; }

void Color::r(int r) { _r = r; }

void Color::g(int g) { _g = g; }

void Color::b(int b) { _b = b; }
