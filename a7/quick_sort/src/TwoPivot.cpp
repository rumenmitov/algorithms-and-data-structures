#include <cstdlib>
#include <ctime>
#include <utility>

#include "TwoPivot.h"


std::pair<int, int> two_pivot_partition
    (std::vector<int>& arr, int lo, int hi) 
{
    /*
     * INFO:
     * Here I am finding the second pivot the same way as the regular Lomoto
     * partitioning. Then I partition the sub-array from lo to pivot_2_idx with
     * pivot_1_idx. For this to work, arr[pivot_1_idx] <= arr[pivot_2_idx].
     */

    int pivot_1_idx = lo;
    int pivot_2_idx = lo + 1;

    if (arr[pivot_1_idx] > arr[pivot_2_idx]) 
        std::swap(arr[pivot_1_idx], arr[pivot_2_idx]);

    if (hi - lo == 2) return std::make_pair(pivot_1_idx, pivot_2_idx);

    int cursor_idx = pivot_2_idx + 1;

    while (cursor_idx < hi) {
        if (arr[cursor_idx] < arr[lo + 1]) {
            pivot_2_idx++;
            std::swap(arr[cursor_idx], arr[pivot_2_idx]);
        }
        cursor_idx++;
    }

    std::swap(arr[pivot_2_idx], arr[lo + 1]);


    cursor_idx = pivot_1_idx + 1;

    while (cursor_idx < pivot_2_idx) {
        if (arr[cursor_idx] < arr[lo]) {
            pivot_1_idx++;
            std::swap(arr[cursor_idx], arr[pivot_1_idx]);
        }
        cursor_idx++;
    }

    std::swap(arr[pivot_1_idx], arr[lo]);


    return std::make_pair(pivot_1_idx, pivot_2_idx);
}


std::pair<int, int> random_two_pivot_paritiion
    (std::vector<int>& arr, int lo, int hi) 
{
    srand(time(nullptr));

    int rand_idx_1, rand_idx_2;
    do {
        rand_idx_1 = (rand() % (hi - lo)) + lo;
        rand_idx_2 = (rand() % (hi - lo)) + lo;
    } while (rand_idx_1 != rand_idx_2);

    /*
     * INFO:
     * We want to partition the larger random index first, because 
     * then we can partition the smaller random index up to it.
     */

    if (hi - lo < 2) return std::make_pair(0, 0);

    std::swap(arr[lo], arr[rand_idx_1]);
    std::swap(arr[lo + 1], arr[rand_idx_2]);

    if (arr[lo] > arr[lo + 1]) {
        std::swap(arr[lo], arr[lo + 1]);
    }

    int pivot_1_idx = lo + 1;
    int cursor_idx = lo + 2;
    
    while (cursor_idx < hi) {
        if (arr[cursor_idx] < arr[lo + 1]) {
            pivot_1_idx++;
            std::swap(arr[cursor_idx], arr[pivot_1_idx]);
        }
        cursor_idx++;
    }

    std::swap(arr[lo + 1], arr[pivot_1_idx]);

    int pivot_2_idx = lo;
    cursor_idx = lo + 1;

    while (cursor_idx < pivot_1_idx) {
        if (arr[cursor_idx] < arr[lo]) {
            pivot_2_idx++;
            std::swap(arr[cursor_idx], arr[pivot_2_idx]);
        }
        cursor_idx++;
    }

    std::swap(arr[lo], arr[pivot_2_idx]);

    return std::make_pair(pivot_2_idx, pivot_1_idx);
}
