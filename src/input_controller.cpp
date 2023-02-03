#include "input_controller.h"

#include <iostream>
#include "SDL.h"

// handle input
void InputController::HandleInput(bool &isRunning, bool &showUI, std::vector<std::shared_ptr<UIElement>> uiElements)
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
                        if (uiElement->GetName() == "zoom")
                        {
                            _imageCreator->SetZoom(uiElement->GetValue());
                            _imageCreator->Update();
                        }
                        if (uiElement->GetName() == "iterations")
                        {
                            _imageCreator->SetIterations(uiElement->GetValue());
                            _imageCreator->Update();
                        }
                    }
                }
            }
        }

        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }

        // Handle mouse events
        // handle doubleClick to toggle showGui, handle mouse wheel to zoom in and out, handle one mouse clik to move image
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (event.button.clicks == 2)
                {
                    showUI = !showUI;
                }
            }
            if (event.type == SDL_MOUSEWHEEL)
            {
                if (event.wheel.y > 0)
                {
                    _imageCreator->SetZoom(_imageCreator->GetZoom() + 0.1);
                    _imageCreator->Update();
                }
                else if (event.wheel.y < 0)
                {
                    _imageCreator->SetZoom(_imageCreator->GetZoom() - 0.1);
                    _imageCreator->Update();
                }
            }
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                // _imageCreator->SetMousePosition(mouse.x, mouse.y);
                _imageCreator->NextFractal();
            }
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
                // Left Arrows Key
            case SDLK_LEFT:
                // _imageCreator->MoveImage(-1, 0);
                break;
                // Right Arrows Key
            case SDLK_RIGHT:
                // _imageCreator->MoveImage(1, 0);
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
