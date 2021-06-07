cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

# set(CXX_FLAGS "-Wall")

# -stdlib=libc++ or GCC 8: -pthread -lstdc++fs 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lstdc++fs")

project(fractal-creator)

add_executable(${PROJECT_NAME} src/main.cpp src/abstract_image.cpp  src/mandelbrot_image.cpp src/color.cpp src/prof_timer.cpp)

# link_libraries(stdc++fs)
target_link_libraries(${PROJECT_NAME}  ${SDL2_LIBRARIES})
