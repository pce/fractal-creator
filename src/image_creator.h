#ifndef IMAGE_CREATOR_H
#define IMAGE_CREATOR_H

#include <string>
#include <vector>

class ImageCreator
{
public:
    ImageCreator(
        std::string fractal,
        int width,
        int height,
        int zoom,
        int zoom_to,
        int iterations) : _width(width), _height(height), _zoom(zoom), _zoom_to(zoom_to), _iterations(iterations) {}
    ImageCreator() {}
    void Create();
    void Update();
    std::vector<int> Render();
    // SetFractal(std::string fractal);
    // SetZoom(int zoom);
    // SetZoomTo(int zoom_to);
    // SetIterations(int iterations);
    // SetWidth(int width);
    // SetHeight(int height);
    // SetFilename(std::string filename);
    // SetPath(std::string path);
    // SetFiletype(std::string filetype);

private:
    std::string _fractal = "Mandelbrot";
    int _width = 640;
    int _height = 640;
    int _zoom = 100;
    int _zoom_to = 0;
    int _iterations = 0;
    std::vector<int> pixel_array;
};

#endif
