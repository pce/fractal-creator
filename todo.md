## TODO

async events (SDL2)

https://www.codeproject.com/Articles/1256352/CppEvent-How-to-Implement-Events-using-Standard-Cp 
https://bastian.rieck.me/blog/posts/2015/event_system_cxx11/ 

https://www.parallelrealities.co.uk/tutorials/widgets/widgets5.php


https://github.com/Acry/SDL2-Slider/blob/master/src/2.c 

https://github.com/kallisti5/guisan/blob/master/src/sdl/sdl2graphics.cpp

https://bastian.rieck.me/blog/posts/2015/simple_fractals_shader/ 




- integrate with SDL2 for GUI: https://github.com/jesseyeh/ppmviewer/blob/master/ppmviewer.cpp 
- or integrate ~ImGUI for controls?
  https://github.com/ocornut/imgui 
  

 - Surface loading: https://lazyfoo.net/SDL_tutorials/lesson02/index.php 
  - Particles: https://lazyfoo.net/tutorials/SDL/38_particle_engines/index.php 
  

SDL2 and DearIMGUI
- https://github.com/ocornut/imgui/blob/92d0924b82dcc1c7159977d29a9c5044ff85459d/examples/example_sdl_sdlrenderer/main.cpp

- https://martin-fieber.de/blog/gui-development-with-cpp-sdl2-and-dear-imgui/

  https://github.com/retifrav/sdl-imgui-example/blob/master/CMakeLists.txt 



 // IDEA calculate -> draw_polygon/rect, for example a SierpinskiCarpet or
  // Pythagoras Tree (as PixelArray) SimpleImage::value returns the value from
  // the precalculation

  vector[(row * columns) + column] -> `PixelArray::get_value(x, y)`

  // unsigned int rgb_val = pixel_array[(x * y) + y];
  // std::cout << "color.rgb_to_hex: " << color.rgb_to_hex() << " from:" <<
  // rgb_val << std::endl; color.hex_to_rgb(rgb_val);

    std::cerr <<"SimpleImage::set_pixel out_of_range value: " <<  y * _width + x 
    << ", x: " << x << ", y: "  << y << ", w: "  << _width << e.what() << std::endl;




    // [(row * columns) + column]

    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15


