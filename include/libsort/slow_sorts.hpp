/*
This file contains all of the sorting algorithms that are far too slow to be usedto any practical extent, but are of
educational or theoretical interest.
*/
#ifndef _LIBSORT_HPP_
#define _LIBSORT_HPP_
#include <libsort/types.hpp>
namespace libsort {
  // Bubble sort.
  void bubble_sort(sort_list& list);

  // Selection sort.
  void selection_sort(sort_list& list);
  
  // worse than n^2 runtime below!
  
  // Stooge sort.
  void stooge_sort(sort_list& list);
  
  // Bogo sort.
  void bogo_sort(sort_list& list);
  
}

#endif