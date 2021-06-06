cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

# set(CXX_FLAGS "-Wall")
# set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

project(fractal-creator)

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(${PROJECT_NAME} src/main.cpp src/abstract_image.cpp  src/mandelbrot_image.cpp src/color.cpp src/prof_timer.cpp)

# string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
# target_link_libraries(${PROJECT_NAME}  ${SDL2_LIBRARIES})
