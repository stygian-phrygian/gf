# project meta data
cmake_minimum_required(VERSION 3.15)
project(main)

# add the cmake directory to the cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# dependencies
# sudo apt install libncurses-dev
find_package(LIBCURSES REQUIRED)

add_subdirectory(src)
add_subdirectory(apps)

