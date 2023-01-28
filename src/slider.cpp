#include "slider.h"

#include <iostream>
#include "SDL.h"

void Slider::Draw(SDL_Renderer *renderer)
{
    // math.map
    auto map = [](int val, int in_min, int in_max, int out_min, int out_max)
    {
        return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    };

    // horizontal slider
    SDL_Rect borderRect = {_x, _y, _w, _h};

    int widthByValue = map(_value, _min, _max, 0, _w);

    SDL_Rect valueRect = {_x, _y, widthByValue, _h};

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &borderRect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &valueRect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &valueRect);
}

void Slider::Update() {}

void Slider::SetValue(int value)
{
    _value = value;
}

void Slider::SetMin(int min)
{
    _min = min;
}

void Slider::SetMax(int max)
{
    _max = max;
}

void Slider::SetMousePosition(int x, int y)
{
    // math.map
    auto map = [](int val, int in_min, int in_max, int out_min, int out_max)
    {
        return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    };

    std::cout << "Mouse clicked at: " << x << ", " << y << std::endl;
    if (HitTest(x, y))
    {
        _value = map(x - _x, 0, _w, _min, _max);
        // _value = x - _x;
        std::cout << "Mouse clicked on slider, value: " << _value << std::endl;
    }
}

bool Slider::HitTest(int x, int y)
{
    if (x >= _x && x <= _x + _w && y >= _y && y <= _y + _h)
    {
        return true;
    }
    return false;
}
