#include "color.h"

Color::Color(std::string hex_color) { hex_to_rgb(hex_color); }

void Color::hex_to_rgb(std::string hex_color) {
  unsigned int hex_val = std::stoul(hex_color, nullptr, 16);
  _r = ((hex_val >> 16) & 0xFF) / 255.0;
  _g = ((hex_val >> 8) & 0xFF) / 255.0;
  _b = ((hex_val)&0xFF) / 255.0;
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
