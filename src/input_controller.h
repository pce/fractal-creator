#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include "image_creator.h"
#include "ui_element.h"

class ImageCreator;

class InputController
{
public:
    void HandleInput(bool &isRunning, bool &showUI, std::vector <UIElement*> uiElements);
    void SetImageCreator(ImageCreator &imageCreator);

private:
    ImageCreator *_imageCreator;
};

#endif
