/*
These aren't all fast per se, they are all useful to some degree though.
*/
#ifndef _LIBSORT_FAST_SORTS_HPP_
#define _LIBSORT_FAST_SORTS_HPP_

#include <libsort/types.hpp>

namespace libsort {
  
  void insertion_sort(sort_list& list);
  
  void merge_sort(sort_list& list);
  
  void quick_sort(sort_list& list);
  
  void heap_sort(sort_list& list);
  
  void radix_sort(sort_list& list);
  
}

#endif