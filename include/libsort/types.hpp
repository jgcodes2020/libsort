#ifndef _LIBSORT_COMMON_HPP_
#define _LIBSORT_COMMON_HPP_
#include <vector>
#include <cstdint>
#include <cstddef>

namespace libsort {
  using sort_list = std::vector<std::uint32_t>;
  
  template<typename T>
  void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
  }
}

#endif