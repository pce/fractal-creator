#ifndef MANDELBROT__IMAGE_H
#define MANDELBROT__IMAGE_H

#include "abstract_image.h"
#include "color.h"

class MandelbrotImage : public AbstractImage {
 public:
  // using initialization lists to initialize the parent class
  MandelbrotImage(int width, int height) : AbstractImage(width, height) {}
  void set_iterations(int iterations);

 protected:
  /** \brief Color value implementation  */
  Color value(int x, int y) override;
  /** \brief Integer maximum of iterations */
  int _iterations = 34;
};

#endif