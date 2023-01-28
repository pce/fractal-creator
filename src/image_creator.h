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
    std::vector<int> const &GetPixelArray() const;
    void SetFractal(std::string fractal);
    void SetZoom(int zoom);
    void SetZoomTo(int zoom_to);
    void SetIterations(int iterations);
    void SetWidth(int width);
    void SetHeight(int height);
    void SetFilename(std::string filename);
    void SetPath(std::string path);
    // void SetFiletype(std::string filetype);

private:
    std::string _fractal = "Mandelbrot";
    std::string _filename = "";
    std::string _path = "";
    int _width = 640;
    int _height = 640;
    int _zoom = 100;
    int _zoom_to = 0;
    int _iterations = 0;
    std::vector<int> pixel_array;
};

#endif
