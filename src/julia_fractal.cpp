
#include "julia_fractal.h"

#include <fstream>
#include <iostream>

void JuliaFractal::init()
{
    std::cout << "JuliaFractal::init " << std::endl;
    pixel_array.resize(_width * _height + 1);
    pixel_array.reserve(_width * _height + 1);
}

void JuliaFractal::set_pixel(int x, int y)
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
        std::cerr << "Exception JuliaFractal::set_pixel out_of_range: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception JuliaFractal::set_pixel: " << e.what() << std::endl;
    }
    // std::cout << "JuliaFractal::set_pixel " << _color << std::endl;
}

unsigned int JuliaFractal::get_pixel(int x, int y)
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

void JuliaFractal::draw_bg(unsigned int color)
{
    for (int i = 0; i <= _height * _width; i++)
    {
        pixel_array[i] = color;
    }
}

void JuliaFractal::draw_rect(int x1, int y1, int x2, int y2)
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

void JuliaFractal::set_color(unsigned int color) { _color = color; }

Color JuliaFractal::value(int x, int y)
{
    unsigned int rgb_val = get_pixel(x, y);
    Color color{rgb_val};
    return color;
}

void JuliaFractal::calculate()
{
    draw_bg(0xFFFFFF);
    int iterations;
    double zx, zy, cx, cy, tmp;
    for (int x = 0; x < _width; x++)
    {
        for (int y = 0; y < _height; y++)
        {
            zx = 1.5 * (x - _width / 2) / (_width / 4);
            zy = (y - _height / 2) / (_height / 4);
            cx = _constant_real;
            cy = _constant_imag;
            iterations = 0;

            while (zx * zx + zy * zy < 4 && iterations < _iterations)
            {
                tmp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = tmp;
                iterations++;
            }
            set_color(solid_rainbow(iterations, _iterations).GetRGB());
            set_pixel(x, y);
        }
    }
}
