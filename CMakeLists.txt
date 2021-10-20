cmake_minimum_required(VERSION 3.15)
project(libsort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)


add_library(sort
  "src/slow/bubble_sort.cpp"
  "src/slow/selection_sort.cpp"
  "src/slow/stooge_sort.cpp"
  "src/slow/bogo_sort.cpp"
)
target_include_directories(sort
  PUBLIC include
)

add_executable(test_libsort
  "test/main.cpp"
)
target_link_libraries(test_libsort sort)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)