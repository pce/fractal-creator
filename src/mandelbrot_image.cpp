#include "mandelbrot_image.h"
#include "color.h"

#include <complex>
#include <fstream>
#include <iostream>
#include <stdexcept>



Color MandelbrotImage::value(int x, int y) {

    // unsigned int max_iterations = 84;
    unsigned int max_iterations = 34;
    // unsigned int max_iterations = 100;
    // unsigned int max_iterations = 68;
    
    double scale =  static_cast<double>(_zoom) / 100;
    // double scale = 1.0;
    // double scale = 2.0;
    // std::cout << "scale:" <<  scale << "\n";

    // Nice to have: set_options  left, top
    double left = 1.5;
    double top = 0.5;

    // double left = 0.5;
    // double top = 1;

    // double left = 1.5;
    // double top = 1.5;

    std::complex<double> c{(static_cast<float>(x)/_width-left)*scale, (static_cast<float>(y)/_height-top)*scale};

    // std::complex<double> c{(float)x/(width-left)*(int)scale, (float)y/(height-top)*(int)scale};
    // std::complex<double> c{(float)x/width-left, (float)y/height-top};
    std::complex<double> z{0, 0};

    unsigned int iteration = 0;
    while (iteration < max_iterations) {
        // calculate the mandelbrot function
        // Complex multiplication, then addition
        z = z*z + c;

        // higher smoother shading
        if (std::abs(z) > 32.0) break;

        iteration++;
    }

    // int r_val = 0;
    int r_val = 255;
    // int g_val = 0;
    int g_val = 255;
    // int b_val = 0;
    int b_val = 255;
    //   r_val = static_cast<int>(iteration * 255.0 / max_iterations);            
    
    Color color{r_val, g_val, b_val};

    if (iteration < max_iterations) {
        // color = long_rainbow(max_iterations * 3, iteration);
        color = long_rainbow(max_iterations * 0.75, iteration);
    }
    return color;
}

