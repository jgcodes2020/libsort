#include <libsort/slow_sorts.hpp>

/*
This is stooge sort, named after The Three Stooges.

It's a recursive sorting algorithm with high time complexity, and works like this:

1. Stooge sort the first 2/3 of the array.
2. Stooge sort the last 2/3 of the array.
3. Stooge sort the first 2/3 again.

This recursiveness keeps going untill we're at single elements, at which point we can just compare and swap.

Its time complexity comes out to be O(n^(log(3) / log(3/2))). This is not trivial to derive.
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
      libsort::swap(list[begin], list[end]);
    }
  }
}

namespace libsort {
  void stooge_sort(sort_list& list) {
    stooge_sort_impl(list, 0, list.size() - 1);
  }
}