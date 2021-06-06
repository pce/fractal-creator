#ifndef MANDELBROT__IMAGE_H
#define MANDELBROT__IMAGE_H

#include "abstract_image.h"
#include "color.h"

class MandelbrotImage : public AbstractImage {
    public:
        // using initialization lists to initialize the parent class
        MandelbrotImage(int width, int height) : AbstractImage(width, height) {}
    protected:
        Color value(int x, int y) override;
};

#endif