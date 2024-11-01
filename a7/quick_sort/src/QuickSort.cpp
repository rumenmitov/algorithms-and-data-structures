#include "QuickSort.h"

void quick_sort(
        std::vector<int>& arr,
        int lo, 
        int hi, 
        int (*partition)(std::vector<int>&, int, int)) 
{
    if (hi - lo < 2) return;

    int pivot = partition(arr, lo, hi);
    quick_sort(arr, lo, pivot, partition);
    quick_sort(arr, pivot + 1, hi, partition);
}


void quick_sort_2_pivots(
        std::vector<int>& arr,
        int lo,
        int hi,
        std::pair<int, int> 
            (*two_pivot_partition)(std::vector<int>&, int, int))
{
    if (hi - lo < 2) return;

    std::pair<int, int> pivots = two_pivot_partition(arr, lo, hi);

    quick_sort_2_pivots(arr, lo, pivots.first, two_pivot_partition);
    quick_sort_2_pivots(arr, pivots.first + 1, pivots.second, two_pivot_partition);
    quick_sort_2_pivots(arr, pivots.second + 1, hi, two_pivot_partition);
}

