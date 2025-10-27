cmake_minimum_required(VERSION 3.10)
project(hello_window VERSION 1.0.0)

# find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED) # this was added because glfw wasn't found through target_link_libraries(hello_window glfw)

add_executable(hello_window src/config.h src/main.cpp)
target_link_libraries(hello_window glfw)
target_include_directories(hello_window PRIVATE dependencies)