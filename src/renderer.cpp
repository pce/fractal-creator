#include "renderer.h"
#include "color.h"

bool Renderer::InitRenderer()
{
    // Init sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                  << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow("SDL2 Fractal Pixel Drawing",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_width, screen_height, 0);

    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
                  << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
                  << std::endl;
        return false;
    }

    return true;
}

void Renderer::Render(std::vector<int> const &pixelArray, bool showUI)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    int i = 0;
    for (auto &colorValue : pixelArray)
    {
        Color color = Color{static_cast<unsigned int>(colorValue)};
        SDL_SetRenderDrawColor(renderer, color.r(), color.g(), color.b(), 255);
        int x = i % screen_width;
        int y = i / screen_width;
        // std::cout << "x: " << x << " y: " << y << std::endl;
        SDL_RenderDrawPoint(renderer, x, y);
        i++;
    }
    if (showUI)
    {
        for (auto &uiElement : uiElements)
        {
            uiElement->Draw(renderer);
        }
    }

    SDL_RenderPresent(renderer);
}

void Renderer::AddUIElement(UIElement *element)
{
    uiElements.push_back(element);
}

// destructor destroys the window and renderer
Renderer::~Renderer()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
