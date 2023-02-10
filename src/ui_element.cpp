
#include "ui_element.h"


bool UIElement::IsMouseOver(int x, int y)
{
    if (x >= _x && x <= _x + _w && y >= _y && y <= _y + _h)
    {
        return true;
    }
    return false;
}