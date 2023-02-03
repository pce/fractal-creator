#include "button.h"

#include <iostream>
#include "SDL.h"

void Button::Draw(SDL_Renderer *renderer)
{
    SDL_Rect borderRect = {_x, _y, _w, _h};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &borderRect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &borderRect);

    SDL_Color textColor = {0, 0, 0, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(_font, _label.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int textW = 0, textH = 0;
    SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
    SDL_Rect textRect = {_x + (_w - textW) / 2, _y + (_h - textH) / 2, textW, textH};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void Button::Update() {}

// void Button::SetValue(int value)
// {
//     _value = value;
// }

void Button::SetMin(int min)
{
    _min = min;
}

void Button::SetMax(int max)
{
    _max = max;
}

void Button::SetMousePosition(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << ", " << y << std::endl;
    if (HitTest(x, y))
    {
        std::cout << "Mouse clicked on button: " << _label << std::endl;
    }
}

bool Button::HitTest(int x, int y)
{
    if (x >= _x && x <= _x + _w && y >= _y && y <= _y + _h)
    {
        return true;
    }
    return false;
}

void Button::SetLabel(const std::string &label)
{
    _label = label;
}

void Button::SetName(const std::string &name)
{
    _name = name;
}

void Button::SetX(int x)
{
    _x = x;
}

void Button::SetY(int y)
{
    _y = y;
}

void Button::SetW(int w)
{
    _w = w;
}

void Button::SetH(int h)
{
    _h = h;
}
