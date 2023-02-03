#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include "image_creator.h"
#include "ui_element.h"
#include <memory>
#include <vector>


class ImageCreator;

class InputController
{
public:
    void HandleInput(bool &isRunning, bool &showUI, std::vector<std::shared_ptr<UIElement>> uiElements);
    void SetImageCreator(ImageCreator &imageCreator);

private:
    ImageCreator *_imageCreator;
};

#endif
