#include <algorithm>
#include <utility>

#include "Median.h"


int median_partition(std::vector<int>& arr, int lo, int hi) {

    /*
     * INFO:
     * Source:
     * https://stackoverflow.com/a/7560859
     */
    int middle = (hi + lo) / 2;

    if (arr[lo] > arr[middle]) std::swap(arr[lo], arr[middle]);
    if (arr[middle] > arr[hi - 1]) std::swap(arr[middle], arr[hi - 1]);
    if (arr[lo] > arr[hi - 1]) std::swap(arr[lo], arr[middle]);

    std::swap(arr[middle], arr[lo]);

    int current_idx = lo;
    int cursor_idx = lo + 1;

    while (cursor_idx < hi) {
        if (arr[cursor_idx] < arr[lo]) {
            current_idx++;
            std::swap(arr[current_idx], arr[cursor_idx]);
        }

        cursor_idx++;
    }

    std::swap(arr[current_idx], arr[lo]);

    return current_idx;
}

