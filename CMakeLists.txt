cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# set(CXX_FLAGS "-Wall")

# see https://gitlab.kitware.com/cmake/cmake/-/issues/17834
# if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lstdc++fs")
# else()
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
# endif()

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lstdc++fs")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(fractal-creator)

add_executable(${PROJECT_NAME} src/main.cpp src/abstract_image.cpp src/simple_image.cpp src/mandelbrot_image.cpp src/color.cpp src/prof_timer.cpp)
  
# target_link_libraries(${PROJECT_NAME} std++fs)