#include <chrono>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

/**
 * @brief Sorts element in-place.
 * 
 * @param int* arr
 * @param size_t n
 * @param size_t curr
 * 
 * @return void
*/
void selection_sort(int* arr, size_t n, size_t curr) {

    // Loop sort for all indices in array.
    for (size_t i = curr; i < n; i++) {

        // Get index of minimum value on the right.
        int min_index = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) min_index = j;
        }

        // Swap current with minimum value.
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

    }
}

/**
 * @brief Creates and returns an array of size n which contains random values
 *        from 1 to 100.
 * 
 * @param size_t n
 * 
 * @return int*
*/
int* generate(size_t n) {
    int* res = new int[n];
    memset(res, 0, n);

    // Setting the seed.
    srand( time(nullptr) );

    for (size_t i = 0; i < n; i++) {
        // Generating random number from 1 to 100.
        res[i] = rand() % 100 + 1;
    }

    return res;
}

/**
 * @brief Measures the time it takes to sort an array of size N.
 * 
 * @param int* arr
 * @param size_t N
 * @param size_t curr
 * @param bool multiple_attempts
 * 
 * @return size_t Returns duration of sort in microseconds.
*/
size_t measure_sort(int* arr, size_t N, size_t curr, bool multiple_attempts) {
        
    if (multiple_attempts) {
        // NOTE: Run multiple times for more accurate results.
        int* tmp1 = new int[N];
        int* tmp2 = new int[N];
        int* tmp3 = new int[N];

        for (size_t i = 0; i < N; i++) {
            tmp1[i] = arr[i];
            tmp2[i] = arr[i];
            tmp3[i] = arr[i];
        }
        selection_sort(tmp1, N, 0);
        selection_sort(tmp2, N, 0);
        selection_sort(tmp3, N, 0);
    }
        
    // Get final time.
    /*
     * Source: 
     * - www.techiedelight.com/measure-elapsed-time-program-chrono-library/
     */
    auto start = std::chrono::steady_clock::now();
    selection_sort(arr, N, 0);
    auto stop = std::chrono::steady_clock::now();

    using namespace std::chrono;
    return duration_cast<microseconds>(stop - start).count();
}


int main(int argc, char** argv) {
    size_t N = atoi(argv[1]);

    std::ofstream results_average("build/results_average.txt");
    std::ofstream results_worst("build/results_worst.txt");
    std::ofstream results_best("build/results_best.txt");

    for (size_t i = 1; i <= N; i++) {
        int* arr = generate(i);

        // Average Case
        results_average 
            << i 
            << "\t" 
            << measure_sort(arr, i, 0, true) 
            << std::endl;

        // Case B: Best Case
        results_best << i << "\t" << measure_sort(arr, i, 0, false) << std::endl;

        // Case A: Worst Case
        /*
         * NOTE: 
         * Worst case is when elements are reverse sorted and last element
         * is swapped with first element.
         */

        // Reverse sort array.
        qsort(arr, i, sizeof(int), [](const void* a, const void* b)->int {
                return *((int*)b) - *((int*)a);
                });

        int temp = arr[i -1];
        arr[i-1] = arr[0];
        arr[0] = temp;

        results_worst << i << "\t" << measure_sort(arr, i, 0, false) << std::endl;

        delete[] arr;

    }

    results_average.close();
    results_worst.close();
    results_best.close();

    return 0;
}
