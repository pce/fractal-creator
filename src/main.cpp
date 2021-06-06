#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <future>
#include <utility>
#include <vector>

#include "prof_timer.h"
#include "mandelbrot_image.h"
// #include "simple_image.h"


int opt_int(std::string arg, int ret) {
    std::size_t pos;

    try {
        ret = std::stoi(arg, &pos);
        if (pos < arg.size()) {
            std::cerr << "Trailing characters after number: " << arg << '\n';
        }
    } catch (std::invalid_argument const &ex) {
        std::cerr << "Invalid number: " << arg << '\n';
    } catch (std::out_of_range const &ex) {
        std::cerr << "Number out of range: " << arg << '\n';
    }
    return ret;
}


int main(int argc, char *argv[])
{
    std::string fractal = "Mandelbrot";

    // full-hd is --width 1920 --height 1080 
    // TODO:  zoom 0.5-2.5 (threads) iterations 123 
    int width = 1920;
    int height = 1920;
    int zoom = 100;
    int zoom_to = 0;
   

    for (int i = 0; i < argc; ++i) {
        if (std::string(argv[i]) == "--fractal" && i + 1 < argc) {
            fractal = argv[i++]; 
        }
        if (std::string(argv[i]) == "--width" && i + 1 < argc) {
            std::string arg = argv[++i];
            width = opt_int(arg, width);
            std::cout << "option set width " <<  width << "px" << std::endl;
        }
        if (std::string(argv[i]) == "--height" && i + 1 < argc) {
            std::string arg = argv[++i];
            height = opt_int(arg, height);
            std::cout << "option set height " <<  height << "px" << std::endl;
        }
        if (std::string(argv[i]) == "--zoom" && i + 1 < argc) {
            std::string arg = argv[++i];
            zoom = opt_int(arg, zoom);
            std::cout << "option set zoom " <<  zoom << "%" << std::endl;
        }
        if (std::string(argv[i]) == "--zoom-to" && i + 1 < argc) {
            std::string arg = argv[++i];
            zoom_to = opt_int(arg, zoom_to);
            std::cout << "option set zoom-to " <<  zoom_to << "%" << std::endl;
        }
        // if (std::string(argv[i]) == "--iterations" && i + 1 < argc) {
        //     std::string arg = argv[++i];
        //     zoom_to = opt_int(arg, zoom_to);
        //     std::cout << "set zoom-to " <<  zoom_to << "%" << std::endl;
        // }
    }

    ProfTimer timer; 
    std::vector<std::future<int> > futures;
    std::mutex  mutex;

    if (fractal == "Mandelbrot") {

        int zoom_step = 10;

        if (zoom_to == 0) {
            zoom_to = zoom;
        }
        for(int i = zoom; i <= zoom_to; i+=zoom_step) {
            futures.push_back (std::async([width, height, &mutex](int i) {
                std::unique_lock<std::mutex> guard(mutex);
                MandelbrotImage img{width, height};
                img.set_zoom(i);        
                img.render();
                return i;
            } , i));

        }

        // retrieve results 
        for(auto &e : futures) {
            std::cout << "file with zoom: " << e.get() << "% written in " <<  timer.elapsed() << "ms" << std::endl;
        }
        
        // std::cout << "files written in " <<  timer.elapsed() << "ms" << std::endl;

    } else {
        std::cout << "unknown fractal" << std::endl; 
        return 1;
    }

    return 0;
}
