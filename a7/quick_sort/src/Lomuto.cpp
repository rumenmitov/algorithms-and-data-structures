#include "Lomuto.h"
#include <utility>

int lomuto_partition(std::vector<int>& arr, int lo, int hi) {
    std::swap( arr[hi - 1], arr[lo] );

    int pivot_idx = lo, cursor_idx = lo + 1;

    while (cursor_idx < hi) {
        if (arr[cursor_idx] < arr[lo]) {
            pivot_idx++;
            std::swap( arr[pivot_idx], arr[cursor_idx] );
        }

        cursor_idx++;
    }

    std::swap( arr[lo], arr[pivot_idx] );

    return pivot_idx;
}
