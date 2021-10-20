cmake_minimum_required(VERSION 3.15)
project(libsort)


add_library(sort
  "src/slow/bubble_sort.cpp"
  "src/slow/selection_sort.cpp"
  "src/slow/stooge_sort.cpp"
)
target_include_directories(sort
  PUBLIC include
)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)