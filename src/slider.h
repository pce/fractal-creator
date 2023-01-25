#ifndef SLIDER_H
#define SLIDER_H

#include "ui_element.h"

class Slider : public UIElement {

    void Draw(SDL_Renderer *renderer);
    void Update();
    void SetMousePosition(int x, int y);
    void SetValue(int value);
    void SetMin(int min);
    void SetMax(int max);
    bool HitTest(int x, int y);


protected:
    int _value{0};
    int _min{0};
    int _max{0};

};

#endif