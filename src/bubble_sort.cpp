#include <libsort/slow_sorts.hpp>

namespace libsort {
  void bubble_sort(sort_list &list) {
    // Sort the list only if it's bigger than two elements
    // Otherwise it would result in segfault or gibberish
    // We also know that bubble sort will move the largest element to the end
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
  }
}