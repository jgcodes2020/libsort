/*
This file contains all of the sorting algorithms that are far too slow to be usedto any practical extent, but are of
educational or theoretical interest.
*/
#ifndef _LIBSORT_SLOW_SORTS_HPP_
#define _LIBSORT_SLOW_SORTS_HPP_
#include <libsort/types.hpp>
namespace libsort {
  void bubble_sort(sort_list& list);

  void selection_sort(sort_list& list);
  
  // worse than n^2 runtime below!
  
  void stooge_sort(sort_list& list);
  
  void bogo_sort(sort_list& list);
  
}

#endif