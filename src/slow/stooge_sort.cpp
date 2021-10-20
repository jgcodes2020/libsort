#include <libsort/slow_sorts.hpp>

/*
This is stooge sort, named after The Three Stooges.

It's a recursive sorting algorithm with high time complexity, and works like this:

1. Stooge sort the first 2/3 of the array.
2. Stooge sort the last 2/3 of the array.
3. Stooge sort the first 2/3 again.

This recursiveness keeps going untill we're at single elements, at which point we can just compare and swap.
*/

namespace {
  void stooge_sort_impl(libsort::sort_list& list, size_t begin, size_t end) {
    size_t size = (end - begin + 1);
    // recursively stooge sort if there are at least 3
    if (size >= 3) {
      size /= 3;
      stooge_sort_impl(list, begin, end - size);
      stooge_sort_impl(list, begin + size, end);
      stooge_sort_impl(list, begin, end - size);
    }
    // compare and swap if there are only 2
    if (size == 2 && list[begin] > list[end]) {
      uint32_t tmp = list[begin];
      list[begin] = list[end];
      list[end] = tmp;
    }
  }
}

namespace libsort {
  void stooge_sort(sort_list& list) {
    stooge_sort_impl(list, 0, list.size() - 1);
  }
}