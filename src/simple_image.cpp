#include "simple_image.h"

#include <fstream>


Color SimpleImage::value(int x, int y) {
    // IDEA 
    // precalc_image()  -> draw_polygon/rect, for example a Pythagoras Tree (as PixelArray)
    // SimpleImage::value returns the value from the precalculation `PixelArray::get_value(x, y)`

    // int r_val = 0;
    int r_val = 255;
    // int g_val = 0;
    int g_val = 255;
    // int b_val = 0;
    int b_val = 255;
    //   r_val = static_cast<int>(iteration * 255.0 / max_iterations);            
    
    Color color{r_val, g_val, b_val};

    return color;
}

