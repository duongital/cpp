cmake_minimum_required(VERSION 3.5)
project(MyProgram)

# Specify the include directory for Raylib
include_directories(/opt/homebrew/Cellar/raylib/5.0/include/)

add_executable(MyProgram main.c)

target_link_libraries(MyProgram raylib -L/opt/homebrew/Cellar/raylib/5.0/lib/)
