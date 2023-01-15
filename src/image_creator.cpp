#include "image_creator.h"
#include "mandelbrot_image.h"
#include "simple_image.h"
#include "prof_timer.h"
#include <future>
#include <mutex>
#include <iostream>

void ImageCreator::Create()
{
    // create image here
    ProfTimer timer;
    std::vector<std::future<int>> futures;
    std::mutex mutex;

    int width = _width;
    int height = _height;
    int zoom = _zoom;
    int zoom_to = _zoom_to;
    int iterations = _iterations;

    if (_fractal == "Mandelbrot")
    {
        int zoom_step = 10;

        if (zoom_to == 0)
        {
            zoom_to = zoom;
        }
        for (int i = zoom; i <= zoom_to; i += zoom_step)
        {
            futures.push_back(std::async(
                [iterations, width, height, &mutex](int i)
                {
                    std::unique_lock<std::mutex> guard(mutex);
                    MandelbrotImage img{width, height};
                    img.init();
                    img.set_zoom(i);
                    if (iterations > 0)
                    {
                        img.set_iterations(iterations);
                    }
                    img.render_to_file();
                    return i;
                },
                i));
        }

        // retrieve results
        for (auto &e : futures)
        {
            std::cout << "file with zoom: " << e.get() << "% written in "
                      << timer.elapsed() << "ms" << std::endl;
        }

        // std::cout << "files written in " <<  timer.elapsed() << "ms" <<
        // std::endl;
    }
    else if (_fractal == "SierpinskiCarpet")
    {
        int zoom_step = 10;

        if (zoom_to == 0)
        {
            zoom_to = zoom;
        }

        for (int i = zoom; i <= zoom_to; i += zoom_step)
        {
            futures.push_back(std::async(
                [iterations, width, height, &mutex](int i)
                {
                    std::unique_lock<std::mutex> guard(mutex);
                    SimpleImage img{width, height};
                    img.init();
                    img.set_zoom(i);
                    if (iterations > 0)
                    {
                        // img.set_iterations(iterations);
                    }
                    img.calculate();
                    img.render_to_file();
                    return i;
                },
                i));
        }

        // retrieve results
        for (auto &e : futures)
        {
            std::cout << "file with zoom: " << e.get() << "% written in "
                      << timer.elapsed() << "ms" << std::endl;
        }
    }
    else
    {
        std::cout << "unknown fractal: '" << _fractal << "'" << std::endl;
        // return 1;
    }
}

void ImageCreator::Update()
{
    // experimenting, this should be done in a thread

    if (_fractal == "Mandelbrot")
    {
        MandelbrotImage img{_width, _height};
        img.init();
        img.set_zoom(_zoom);
        if (_iterations > 0)
        {
            img.set_iterations(_iterations);
        }
        img.render_to_file();
        pixel_array = img.get_pixels();
    }
    else
    {
        SimpleImage img{_width, _height};
        img.init();
        img.set_zoom(_zoom);
        img.calculate();
        pixel_array = img.get_pixels();
    }
}

std::vector<int> const &ImageCreator::GetPixelArray() const
{
    return pixel_array;
}
