# CPPND-Capstone: Fractal-Creator 

This is my repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

Optional: `clang-format -style=Google src/* -i` 


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./fractal-creator`.
  Expected output of build `./fractal-creator`:   
  `file with zoom: 100% written in 7614ms`
5. Options are width, height, zoom, iterations
  `./fractal-creator --iterations 99` 


<img src="examples/out-2.png" />

<img src="examples/out-10.png" />

<img src="examples/out-14.png" />

<img src="examples/out-33.png" />



### Build Troubleshooting

Due to the fact that the creator uses modern std-features like thread and filesystem older GCC must know which libraries to link.   

Adjust the CMakefiles.txt
`set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")` or 
`set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lstdc++fs")`




## Overview


Options are width, height, zoom, iterations and the fractal (Mandelbrot, SierpinskiCarpet).

`./fractal-creator --fractal Mandelbrot --iterations 99` 


`./fractal-creator --fractal SierpinskiCarpet`


### Image Concept


AbstractImage is the BaseClass of MandelbrotImage and SimpleImage. 
Childs override `virtual Color value(int x, int y)`.


                +---------------.-+    
                | AbstractImage   |       
                +-----------------+    
                | render()        |    
                +--------^--------+    
                        /_\            
                         |             
               +--------------------             
               |                    |
    +------------------+    +--------------+ 
    | MandelbrotImage  |    | SimpleImage  |   
    +------------------+    +--------------+ 
    | value(x, y)      |    | value(x, y)  |   
    +------------------+    +--------------+    


SimpleImage  is a sample class that holds a precomputed array of pixels, since it is derived from AbstractImage, SimpleImage returns a precomputed value of the private pixel array   

The pixel array is stored one-dimensionally as a simple vector of hexadecimal RGB values. 

      +---- +-----+-----+-----+-----+-----+-----+-----+-----+
      | 0xd | 0xe | 0xf | 0xc | 0xa | 0xa | 0xa | 0xa | 0xa | --+ width * height 
      +-----+ -----+-----+-----+----+-----+-----+-----+-----+ 


Rendered two dimensional  `[ y * width + x ] --+ ( x , y )`
 
      +---- +-----+-----+
      | rgb | rgb | rgb | 
      +-----+ -----+----+
      | rgb | rgb | rgb | 
      +---- +-----+-----+
      | rgb | rgb | rgb | 
      +-----+ -----+----+ 




## License
[MIT](https://choosealicense.com/licenses/mit/)


