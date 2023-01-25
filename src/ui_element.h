#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <vector>

#include "SDL.h"

class UIElement
{
public:
    UIElement() {}
    UIElement(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {}
    virtual ~UIElement() {}

    virtual void Draw(SDL_Renderer *renderer) = 0;
    virtual void Update() = 0;
    virtual void SetMousePosition(int x, int y) = 0;

    // bool IsMouseOver(int x, int y);
    int GetX() { return _x; }
    int GetY() { return _y; }
    int GetW() { return _w; }
    int GetH() { return _h; }

    void SetX(int x) { _x = x; }
    void SetY(int y) { _y = y; }
    void SetW(int w) { _w = w; }
    void SetH(int h) { _h = h; }

protected:
    int _x{0};
    int _y{0};
    int _w{0};
    int _h{0};
};

#endif