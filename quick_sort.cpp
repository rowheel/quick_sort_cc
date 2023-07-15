#include <array>
#include <cstddef>
#include <cstdio>

#include "quick_sort_data.hpp"

template <typename T, size_t N>
void quickSort(std::array<T, N> &array, size_t start = 0, size_t end = N - 1) {
    if (start != end) {
        size_t pivot = start;

        for (size_t index = start; index < end; index++) {
            if (array.at(index) < array.at(end)) {
                std::swap(array.at(index), array.at(pivot++));
            }
        }

        std::swap(array.at(end), array.at(pivot));

        if (start < pivot) {
            quickSort(array, start, pivot - 1);
        }

        if (pivot < end) {
            quickSort(array, pivot + 1, end);
        }
    }
}

int main() {
    quickSort(testData);

    for (size_t ii = 1; ii < testData.size(); ii++) {
        if (testData.at(ii - 1) > testData.at(ii)) {
            printf("[!] Algorithm is not valid\n");
            return 1;
        }
    }

    printf("[*] Algorithm is valid\n");
    return 0;
}
