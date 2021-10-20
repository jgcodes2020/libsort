#include <libsort/slow_sorts.hpp>
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

/*
This is bogo sort, the worst possible sorting algorithm known to man.

Here's how it works:
1. Check if the array is sorted.
2. If it isn't shuffle the array.

It has both the best and worst time complexities possible:
O(n) in the best case, the array is already sorted and it just checks that
O(n * n!) on average, because there are n! perumtations and it takes on average n shuffles to get all of them
O(inf) in the worst case, the RNG never sorts the array
*/

namespace {
  // Too lazy to write my own RNG, going to use std rng
  size_t rand_size_t(size_t min, size_t max) {
    static mt19937 gen = mt19937(random_device()());
    return uniform_int_distribution<size_t>(min, max)(gen);
  }
  bool is_sorted(libsort::sort_list& list) {
    for (size_t i = 0; i < list.size() - 1; i++) {
      if (list[i] > list[i + 1]) return false;
    }
    return true;
  }
}

namespace libsort {
  void bogo_sort(sort_list &list) {
    if (list.size() < 2) return;
    while (!is_sorted(list)) {
      // This is a fair shuffle
      for (size_t i = 0; i < list.size(); i++) {
        size_t swap = rand_size_t(i, list.size() - 1);
        uint32_t tmp = list[i];
        list[i] = list[swap];
        list[swap] = tmp;
      }
    }
  }
}