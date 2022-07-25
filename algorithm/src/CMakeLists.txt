cmake_minimum_required(VERSION 3.20)

# set program name & version
project(Tutorial VERSION 1.0)

# add the executable
add_executable(Doc doc.cxx)

# add sub dir
add_subdirectory(tutorial)
add_subdirectory(lib)
