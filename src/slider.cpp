#include "slider.h"

#include <iostream>
#include "SDL.h"

void Slider::Draw(SDL_Renderer *renderer)
{
    // horizontal slider
    SDL_Rect borderRect = {_x, _y, _w, _h};
    // TODO value should be a percentage of the slider width
    SDL_Rect valueRect = {_x, _y, _value, _h};

    SDL_RenderDrawRect(renderer, &borderRect);
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
    std::cout << "Mouse clicked at: " << x << ", " << y << std::endl;
    if (HitTest(x, y))
    {
        std::cout << "Mouse clicked on slider" << std::endl;
        _value = (x - _x);
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
