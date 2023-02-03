#include <future>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_TTF.h"

#include "mandelbrot_image.h"
#include "prof_timer.h"
#include "sierpinski_carpet.h"
#include "image_creator.h"
#include "input_controller.h"
#include "slider.h"
#include "button.h"
#include "renderer.h"

int opt_int(std::string arg, int ret)
{
  std::size_t pos;

  try
  {
    ret = std::stoi(arg, &pos);
    if (pos < arg.size())
    {
      std::cerr << "Trailing characters after number: " << arg << '\n';
    }
  }
  catch (std::invalid_argument const &ex)
  {
    std::cerr << "Invalid number: " << arg << '\n';
  }
  catch (std::out_of_range const &ex)
  {
    std::cerr << "Number out of range: " << arg << '\n';
  }
  return ret;
}

int main(int argc, char *argv[])
{
  std::string fractal = "Mandelbrot";

  int width = 640;  // 1920;
  int height = 640; // 1920;
  int zoom = 100;
  int zoom_to = 0;
  int iterations = 0;

  for (int i = 0; i < argc; ++i)
  {
    if (std::string(argv[i]) == "--fractal" && i + 1 < argc)
    {
      std::string arg = argv[++i];
      fractal = arg;
    }
    if (std::string(argv[i]) == "--width" && i + 1 < argc)
    {
      std::string arg = argv[++i];
      width = opt_int(arg, width);
      std::cout << "option set width " << width << "px" << std::endl;
    }
    if (std::string(argv[i]) == "--height" && i + 1 < argc)
    {
      std::string arg = argv[++i];
      height = opt_int(arg, height);
      std::cout << "option set height " << height << "px" << std::endl;
    }
    if (std::string(argv[i]) == "--zoom" && i + 1 < argc)
    {
      std::string arg = argv[++i];
      zoom = opt_int(arg, zoom);
      std::cout << "option set zoom " << zoom << "%" << std::endl;
    }
    if (std::string(argv[i]) == "--zoom-to" && i + 1 < argc)
    {
      std::string arg = argv[++i];
      zoom_to = opt_int(arg, zoom_to);
      std::cout << "option set zoom-to " << zoom_to << "%" << std::endl;
    }
    if (std::string(argv[i]) == "--iterations" && i + 1 < argc)
    {
      std::string arg = argv[++i];
      iterations = opt_int(arg, iterations);
      std::cout << "set iterations " << iterations << std::endl;
    }
  }

  ImageCreator imageCreator{fractal, width, height, zoom, zoom_to, iterations};
  imageCreator.Create();

  Renderer renderer{width, height};
  if (!renderer.InitRenderer())
  {
    return 0;
  }

  // controller
  InputController inputController;
  inputController.SetImageCreator(imageCreator);

  // initialize uiElements
  if (TTF_Init() == -1) {
    std::cerr << "Error initializing font: " << TTF_GetError() << std::endl;
    // exit or return error code
}

  TTF_Font* font;
  std::string fontPath = "assets/fonts/Comfortaa-Regular.ttf";
  int fontSize = 12;
  font = TTF_OpenFont(fontPath.c_str(), fontSize);
  if (!font)
  {
    std::cerr << "Error initializing font: " << TTF_GetError() << std::endl;
    return 0;
  }

  int marginTop = 5;
  std::shared_ptr<Slider> sliderZoom = std::make_shared<Slider>();
  sliderZoom->SetH(20);
  sliderZoom->SetW(100);
  sliderZoom->SetX(10);
  sliderZoom->SetY(10);
  sliderZoom->SetMin(0); // 30
  sliderZoom->SetMax(200);
  // sliderZoom->SetValue(50);
  sliderZoom->SetName("zoom");

  renderer.AddUIElement(std::move(sliderZoom));

  std::shared_ptr<Slider> sliderIterations = std::make_shared<Slider>();

  sliderIterations->SetH(20);
  sliderIterations->SetW(100);
  sliderIterations->SetX(10);
  sliderIterations->SetY(30 + marginTop);
  sliderIterations->SetMin(0); // 30
  sliderIterations->SetMax(200);
  // slider->SetValue(50);
  sliderIterations->SetName("iterations");

  renderer.AddUIElement(std::move(sliderIterations));

  std::shared_ptr<Button> buttonNext = std::make_shared<Button>();

  buttonNext->SetFont(font);
  buttonNext->SetH(20);
  buttonNext->SetW(100);
  buttonNext->SetX(10);
  buttonNext->SetY(50 + marginTop);
  buttonNext->SetMin(0); // 30
  buttonNext->SetMax(200);
  buttonNext->SetLabel("Next");
  buttonNext->SetName("buttonNext");
  buttonNext->SetCallback([&imageCreator]() {
    imageCreator.NextFractal();
    imageCreator.Update();    
  });

  renderer.AddUIElement(std::move(buttonNext));

  // update PixelArray
  imageCreator.Update();

  bool isRunning = true;
  bool showUI = false;
  while (isRunning)
  {
    inputController.HandleInput(isRunning, showUI, renderer.GetUiElements());
    // update renderer
    const std::vector<int> pixelArray = imageCreator.GetPixelArray();
    renderer.Render(pixelArray, showUI);
    // delay
    SDL_Delay(1000 / 60);
  }

  TTF_CloseFont(font);
  TTF_Quit();

  return 0;
}
