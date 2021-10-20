#include <libsort/slow_sorts.hpp>
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

/*
This is selection sort, one of the most obvious ways to sort a list.
The idea is incredibly simple: you look for the minimum element, 
and then swap it into place. Then you look at the remaining elements, 
find their minimum and swap that into place. And so on. 

It has a constant O(n^2) runtime, and cannot be pushed any further than that,
as it HAS to check every single element even if they may be in sorted order.
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