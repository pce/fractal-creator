#ifndef SLIDER_H
#define SLIDER_H

#include "ui_element.h"

class Slider : public UIElement {
public:
    void Draw(SDL_Renderer *renderer);
    void Update();
    void SetMousePosition(int x, int y);
    void SetValue(int value);
    void SetMin(int min);
    void SetMax(int max);

protected:
    int _min{0};
    int _max{100};

};

#endif