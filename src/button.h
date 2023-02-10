#ifndef BUTTON_H
#define BUTTON_H

#include "ui_element.h"
#include <string>
#include <functional>

class Button : public UIElement
{
public:
    Button() : _callback(nullptr) {}
    void Draw(SDL_Renderer *renderer);
    void Update();
    void SetMousePosition(int x, int y);
    void SetH(int h);
    void SetW(int w);
    void SetX(int x);
    void SetY(int y);
    void SetMin(int min);
    void SetMax(int max);
    void SetLabel(const std::string &label);
    void SetName(const std::string &name);
    void SetCallback(std::function<void()> callback);

protected:
    std::string _label;
    std::string _name;

private:
    std::function<void()> _callback;

};

#endif