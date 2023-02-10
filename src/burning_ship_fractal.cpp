
#include "burning_ship_fractal.h"

#include <fstream>
#include <iostream>
#include <cmath>
// #include <complex>

void BurningShipFractal::init()
{
    std::cout << "BurningShipFractal::init " << std::endl;
    pixel_array.resize(_width * _height + 1);
    pixel_array.reserve(_width * _height + 1);

    const long double FCT = 2.85;
    long double factor = FCT / _width;
    _constant_real = ( factor * 184 ) + -1.4;
    _constant_imag = ( factor * 307 ) + -2.0;

    // std::complex<long double> c;
    // c.imag( ( factor * 184 ) + -1.4 );
    // c.real( ( factor * 307 ) + -2.0 );
}

void BurningShipFractal::set_pixel(int x, int y)
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
        std::cerr << "Exception BurningShipFractal::set_pixel out_of_range: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception BurningShipFractal::set_pixel: " << e.what() << std::endl;
    }
    // std::cout << "BurningShipFractal::set_pixel " << _color << std::endl;
}

unsigned int BurningShipFractal::get_pixel(int x, int y)
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

void BurningShipFractal::draw_bg(unsigned int color)
{
    for (int i = 0; i <= _height * _width; i++)
    {
        pixel_array[i] = color;
    }
}

void BurningShipFractal::draw_rect(int x1, int y1, int x2, int y2)
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

void BurningShipFractal::set_color(unsigned int color) { _color = color; }

Color BurningShipFractal::value(int x, int y)
{
    unsigned int rgb_val = get_pixel(x, y);
    Color color{rgb_val};
    return color;
}

int BurningShipFractal::calculate_iterations(double zx, double zy, double cx, double cy, int iterations_limit)
{
    double tmp;
    int iterations = 0;
    while (zx * zx + zy * zy < 4 && iterations < iterations_limit)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;
        iterations++;
    }
    return iterations;
}

void BurningShipFractal::calculate()
{
    draw_bg(0xFFFFFF);

    for (int x = 0; x < _width; x++)
    {
        for (int y = 0; y < _height; y++)
        {
            double zx = 1.5 * (x - _width / 2) / (_width / 4);
            double zy = (y - _height / 2) / (_height / 4);
            int iterations = calculate_iterations(zx, zy, _constant_real, _constant_imag, _iterations);
            set_color(solid_rainbow(iterations, _iterations).GetRGB());
            set_pixel(x, y);
        }
    }
}



