cmake_minimum_required(VERSION 3.10) # common to every CLion project
project(carro) # project name

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall")
set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.

file(GLOB CPP_SOURCE
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    )

################################################
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(carroExe main.cpp ${CPP_SOURCE}) #common to all clion project
target_link_libraries(carroExe ${OpenGlLinkers}) # linking opengl libraries to the project

#################################################
