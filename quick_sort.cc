#include <array>

#include <cstddef>
#include <iostream>
#include <thread>

#include "quick_sort_data.h"

template <typename T, size_t N>
void quick_sort(std::array<T, N> &array, size_t start = 0, size_t end = N - 1) {
  if (start == end) {
    return;
  }

  auto pivot = start;

  for (auto index = start; index < end; index++) {
    if (array.at(index) < array.at(end)) {
      std::swap(array.at(index), array.at(pivot++));
    }
  }

  std::swap(array.at(end), array.at(pivot));

  if (start < pivot) {
    quick_sort(array, start, pivot - 1);
  }

  if (pivot < end) {
    quick_sort(array, pivot + 1, end);
  }
}

int main() {
  quick_sort(test_data);

  for (auto element : test_data) {
    std::cout << element << std::endl;
  }

  return 0;
}
