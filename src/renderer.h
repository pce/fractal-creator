#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include <iostream>
#include <vector>

class Renderer
{
public:
    Renderer() {}
    Renderer(int width, int height) : screen_width(width), screen_height(height) {};
    ~Renderer();
    bool InitRenderer();
    void Render(std::vector<int> const &pixelArray);

private:
    SDL_Renderer *renderer;
    SDL_Window *window;

    const std::size_t screen_width = 640;
    const std::size_t screen_height = 640;
};

#endif
