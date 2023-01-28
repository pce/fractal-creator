cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set(CXX_FLAGS "-Wall")
project(fractal-creator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(${PROJECT_NAME} src/main.cpp src/math_util.h src/slider.cpp src/ui_element.cpp src/input_controller.cpp src/renderer.cpp src/abstract_image.cpp src/simple_image.cpp src/mandelbrot_image.cpp src/image_creator.cpp src/color.cpp src/prof_timer.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# target_link_libraries(${PROJECT_NAME} std++fs)