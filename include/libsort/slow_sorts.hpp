#ifndef _LIBSORT_HPP_
#define _LIBSORT_HPP_
#include <libsort/common.hpp>
namespace libsort {
  // Bubble sort.
  void bubble_sort(sort_list& list);

  // Selection sort.
  void selection_sort(sort_list& list);
}

#endif