#include <libsort/slow_sorts.hpp>

/*
This is bubble sort. One of the simplest sorting algorithms in existence.
It works by repeatedly comparing adjacent elements, causing the larger elements
to slowly "bubble" to the top, hence the name.

It runs in O(n^2), but among O(n^2) sorting algorithms, it is incredibly slow.
*/

namespace libsort {
  void bubble_sort(sort_list &list) {
    // We know that bubble sort will move the largest element to the end
    // on each pass so we can progressively loop 1 element less each time
    for (size_t i = list.size(); i > 1; i--) {
      // sorted check allows us to skip a few steps
      // on occasion
      bool sorted = true;
      // iterate to the last sorted element
      for (size_t j = 0; j + 1 < i; j++) {
        // check this element and the one next to it
        // if they're out of order, swap them
        if (list[j] > list[j + 1]) {
          sorted = false;
          uint32_t tmp = list[j];
          list[j] = list[j + 1];
          list[j + 1] = tmp;
        }
      }
      // if the list is somehow already sorted by this point we're done
      if (sorted) break;
    }
    // if we've gone through all iterations we know the list is sorted
  }
}