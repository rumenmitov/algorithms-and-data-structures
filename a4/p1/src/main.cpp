#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>

#include "MergeSort.h"

#ifdef DEBUG
    #include <cassert>
    #include <iostream>
#endif


using namespace std;

int main(int argc, char* argv[]) {
#ifdef DEBUG
    // INFO: Merge Test
    deque<int> left_test {1, 2, 3};
    deque<int> right_test {2, 3, 4, 5};
    deque<int> merged = merge(left_test, right_test);
    deque<int> merged_solution {1, 2, 2, 3, 3, 4 ,5};

    cout << "Test merged deque: ";
    for (int x : merged) {
        cout << x << " ";
    }
    cout << endl;

    assert( merged == merged_solution );

    // INFO: Insertion Sort Test
    deque<int> insertion_test {9, 8, 7};
    deque<int> insertion_solution = {7, 8, 9};
    insertion_sort(insertion_test);

    cout << "Test insertion sort: ";
    for (int x : insertion_test) {
        cout << x << " ";
    }
    cout << endl;

    assert( insertion_test == insertion_solution );

    // INFO: Merge K Sort Test
    deque<int> merge_k_test {9, 8, 7, 6, 5, 4, 3, 2, 1};
    deque<int> merge_k_solution {1, 2, 3, 4, 5, 6, 7, 8, 9};

    merge_k_sort(merge_k_test, 10);

    cout << "Test merge k sort, k > deque.size(): ";
    for (int x : merge_k_test) {
        cout << x << " ";
    }
    cout << endl;

    assert( merge_k_test == merge_k_solution );

    merge_k_sort(merge_k_test, 1);

    cout << "Test merge k sort, k < deque.size(): ";
    for (int x : merge_k_test) {
        cout << x << " ";
    }
    cout << endl;

    assert( merge_k_test == merge_k_solution );

#endif

    ofstream f_avr("build/average.txt");
    ofstream f_best("build/best.txt");
    ofstream f_worst("build/worst.txt");

    int N = 10; // default number of elements in deque
    if ( argv[1] != 0 ) {
        N = atoi(argv[1]);
    }

    deque<int> data = generate_input(N);

    size_t time_taken = 0;


    // INFO: Average Case (randomly sorted data)
    for (int k = 1; k <= N; k++) {
        deque<int> tmp(data);
        // NOTE: Running average case multiple times
        time_taken = measure_sort(tmp, k, true);

        f_avr << k << "\t" << time_taken << endl;
    }

    // INFO: Best Case (pre-sorted data)
    sort(data.begin(), data.end(), [](int a, int b) -> bool {
            return a <= b;
        });

    for (int k = 1; k <= N; k++) {
        deque<int> tmp(data);
        time_taken = measure_sort(tmp, k, false);

        f_best << k << "\t" << time_taken << endl;
    }

    // INFO: Worst Case (reverse-sorted)
    /* 
     * NOTE: I chose reverse-sorted array as a worst case since that
     * is the worst scenario for insertion sort (which in this case is 
     * doing the actual sorting)
     */

    sort(data.begin(), data.end(), [](int a, int b) -> bool {
            return a > b;
        });

    for (int k = 1; k <= N; k++) {
        deque<int> tmp(data);
        time_taken = measure_sort(tmp, k, false);

        f_worst << k << "\t" << time_taken << endl;
    }

    f_avr.close();
    f_best.close();
    f_worst.close();

    return 0;
}
