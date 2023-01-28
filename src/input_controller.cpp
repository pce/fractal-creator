#include "input_controller.h"

#include <iostream>
#include "SDL.h"

// handle input
void InputController::HandleInput(bool &isRunning, bool &showUI, std::vector <UIElement*> uiElements)
{
    SDL_Point mouse;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        SDL_GetMouseState(&mouse.x, &mouse.y);
        // if (event.type == SDL_INPUTBUTTONUP)
        if (event.type == SDL_MOUSEBUTTONUP)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (showUI)
                {
                    for (auto uiElement : uiElements)
                    {
                        uiElement->SetMousePosition(mouse.x, mouse.y);
                        if (uiElement->GetName() == "zoom") {
                            _imageCreator->SetZoom(uiElement->GetValue());
                            _imageCreator->Update();
                        }
                        if (uiElement->GetName() == "iterations") {
                            _imageCreator->SetIterations(uiElement->GetValue());
                        }
                    }
                }
            }
        }

        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        // Handle key events
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            case SDLK_SPACE:
                showUI = !showUI;
                break;
            case SDLK_s:
                // _imageCreator->SaveImage();
                break;
            case SDLK_l:
                // _imageCreator->LoadImage();
                break;
            case SDLK_r:
                // _imageCreator->ResetImage();
                break;
            case SDLK_p:
                // _imageCreator->PrintImage();
                break;
            default:
                break;
            }
        }
    }
}

void InputController::SetImageCreator(ImageCreator &imageCreator)
{
    _imageCreator = &imageCreator;
}

