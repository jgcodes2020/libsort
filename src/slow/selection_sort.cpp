#include <libsort/slow_sorts.hpp>

/*
This is selection sort, one of the most obvious ways to sort a list.
The idea is incredibly simple: you look for the minimum element, 
and then swap it into place. Then you look at the remaining elements, 
find their minimum and swap that into place. And so on. 

It has a constant O(n^2) runtime, and cannot be pushed any further than that,
as it HAS to check every single element even if they may be in sorted order.
*/

namespace libsort {
  void selection_sort(sort_list &list) {
    // i delineates the sorted portion
    for (size_t i = 0; i < list.size(); i++) {
      size_t next = i;
      // linear search for the minimum of the unsorted portion
      for (size_t j = i; j < list.size(); j++) {
        if (list[j] < list[next]) {
          next = j;
        }
      }
      // swap it into its place
      uint32_t tmp = list[i];
      list[i] = list[next];
      list[next] = tmp;
    }
  }
}