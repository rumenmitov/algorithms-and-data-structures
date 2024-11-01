#include <utility>

#include "Hoare.h"

int hoare_partition(std::vector<int>& arr, int lo, int hi) {
    /*
     * NOTE:
     * Based off of the pseudo code found here:
     * https://en.wikipedia.org/wiki/Quicksort
     *
     * and the video explantion:
     * https://www.youtube.com/watch?v=AO8Sav4SmSU
     */

    int pivot = lo;
    int i = lo, j = hi;

    while (true) {
        do {
            i++;
        } while (arr[i] < arr[pivot]);

        do {
            j--;
        } while (arr[j] > arr[pivot]);


        if (i >= j) {
            std::swap(arr[pivot], arr[j]);
            return j;
        }
        std::swap(arr[i], arr[j]);

    }
}

