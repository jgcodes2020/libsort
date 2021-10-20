#include <libsort/fast_sorts.hpp>

/*
This is insertion sort, the most well-known and commonly used O(n^2) sorting algorithm.
Its performance is far better compared to that of selection and bubble sort, and it works
better than most O(n log n) algorithms for small lists.

The idea is also quite simple: you maintain a sorted and unsorted portion.
Each element is then shuffled left through the list until it's in place.
This lends it to this beautiful 5-line implementation (7 lines if you expand the swap).
*/

namespace libsort {
  void insertion_sort(sort_list& list) {
    for (size_t i = 1; i < list.size(); i++) {
      for (size_t j = i; j > 0 && list[j - 1] > list[j]; j--) {
        swap(list[j], list[j - 1]);
      }
    }
  }
}