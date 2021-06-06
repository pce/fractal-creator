#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <sstream>

/**
 * \brief Simple RGB Color   
 * nice to have: Indexed or Grayscale (Palette)
  */
class Color {
    public:
        Color(int r, int g, int b) : _r(r), _g(g), _b(b) {}
        Color() {}
        Color(std::string hex_color);
        int r();
        int g();
        int b();
        void r(int r);
        void g(int g);
        void b(int b);
        void hex_to_rgb(std::string hex_color);
        std::string rgb_to_hex(); 

    private:
        int _r;
        int _g;
        int _b;
};

#endif