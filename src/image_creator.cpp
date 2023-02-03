#include "image_creator.h"
#include "mandelbrot_image.h"
#include "sierpinski_carpet.h"
#include "julia_fractal.h"

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
                    SierpinskyCarpet img{width, height};
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
    // experimenting, should this done async, in a thread?

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
    else if (_fractal == "SierpinskyCarpet") {
        SierpinskyCarpet img{_width, _height};
        img.init();
        img.set_zoom(_zoom);
        img.calculate();
        pixel_array = img.get_pixels();
    } else if (_fractal == "SierpinskiTriangle") {
        // ...
    } else if (_fractal == "Julia") {
        // ...
        JuliaFractal img{_width, _height};
        img.init();
        img.set_zoom(_zoom);
        // if (_iterations > 0)
        // {
        //     img.set_iterations(_iterations);
        // }
        img.calculate();
        pixel_array = img.get_pixels();

    } else {
        std::cout << "unknown fractal: '" << _fractal << "'" << std::endl;
        // return 1;
    }
}

std::vector<int> const &ImageCreator::GetPixelArray() const
{
    return pixel_array;
}

void ImageCreator::SetFractal(std::string fractal)
{
    _fractal = fractal;
}
void ImageCreator::SetZoom(int zoom)
{
    _zoom = zoom;
}

void ImageCreator::SetZoomTo(int zoom_to)
{
    _zoom_to = zoom_to;
}

void ImageCreator::SetIterations(int iterations)
{
    _iterations = iterations;
}

void ImageCreator::SetWidth(int width)
{
    _width = width;
}

void ImageCreator::SetHeight(int height)
{
    _height = height;
}

void ImageCreator::SetFilename(std::string filename)
{
    _filename = filename;
}

void ImageCreator::SetPath(std::string path)
{
    _path = path;
}

void ImageCreator::NextFractal()
{
    _currentFractal = (_currentFractal + 1) % _fractalList.size();
    SetFractal(_fractalList[_currentFractal]);
}

void ImageCreator::PrevFractal()
{
    _currentFractal = (_currentFractal - 1 + _fractalList.size()) % _fractalList.size();
    SetFractal(_fractalList[_currentFractal]);
}

// void ImageCreator::SetColor(int r, int g, int b)
// {
//     _r = r;
//     _g = g;
//     _b = b;
// }
