#include <initializer_list>
#include <random>
#include <algorithm>

#include <type_traits>
#include <vector>

#include <iostream>

#include <libsort/slow_sorts.hpp>

#define assert(cond) details::check(cond, __FILE__, __LINE__, #cond)

namespace details {
  void check(bool cond, const char* file, int line, const char* strcond) {
    if (cond) return;
    std::cerr << "Assertion (" << strcond << ") failed at " __FILE__ ":" << line << std::endl;
    std::exit(1);
  }
}

using namespace libsort;

std::mt19937 stdrand = std::mt19937(std::random_device()());

template<typename... Ts>
void test_all(size_t max, Ts... x) {
  static_assert(std::conjunction_v<std::is_same<void (*)(std::vector<uint32_t>&), Ts>...>, "whut");
  std::vector<uint32_t> v(max);
  std::iota(v.begin(), v.end(), 0);
  
  for (void (*i)(std::vector<uint32_t>&): 
    std::initializer_list<void (*)(std::vector<uint32_t>&)> {x...}) {
    std::shuffle(v.begin(), v.end(), stdrand);
    i(v);
    assert(std::is_sorted(v.begin(), v.end()));
  }
}


int main() {
  test_all(5, bogo_sort);
  test_all(20, stooge_sort);
  test_all(100, bubble_sort, selection_sort);
}