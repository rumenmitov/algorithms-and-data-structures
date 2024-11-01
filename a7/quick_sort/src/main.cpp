#include <iostream>
#include <vector>

#include "Utils.h"
#include "Lomuto.h"
#include "Hoare.h"
#include "Median.h"

#ifdef DEBUG
#include <cassert>

#include "QuickSort.h"
#include "TwoPivot.h"
#endif


using namespace std;

int main(void) {
    
#ifdef DEBUG
    vector<int> sorting_test_1 {0};
    vector<int> sorting_solution_1 {0};
    vector<int> sorting_test_2 { 4, 5, 3, 2, 9, -2, 1, 0 };
    vector<int> sorting_solution_2 { -2, 0, 1, 2, 3, 4, 5, 9 };
    vector<int> test;

    cout << "testing QuickSort with Lomuto...";

    test = sorting_test_1;
    quick_sort(test, 0, test.size(), lomuto_partition);
    assert(test == sorting_solution_1);

    test = sorting_test_2;
    quick_sort(test, 0, test.size(), lomuto_partition);
    assert(test == sorting_solution_2);

    cout << "passed." << endl;


    cout << "testing QuickSort with Hoare...";

    test = sorting_test_1;
    quick_sort(test, 0, test.size(), hoare_partition);
    assert(test == sorting_solution_1);

    test = sorting_test_2;
    quick_sort(test, 0, test.size(), hoare_partition);
    assert(test == sorting_solution_2);

    cout << "passed." << endl;


    cout << "testing QuickSort with Median...";

    test = sorting_test_1;
    quick_sort(test, 0, test.size(), median_partition);
    assert(test == sorting_solution_1);

    test = sorting_test_2;
    quick_sort(test, 0, test.size(), median_partition);
    assert(test == sorting_solution_2);

    cout << "passed." << endl;


    cout << "testing QuickSort with 2-pivots...";

    test = sorting_test_1;
    quick_sort_2_pivots(test, 0, test.size(), two_pivot_partition);
    assert(test == sorting_solution_1);

    test = sorting_test_2;
    quick_sort_2_pivots(test, 0, test.size(), two_pivot_partition);
    assert(test == sorting_solution_2);

    cout << "passed." << endl;


    cout << "testing QuickSort with 2-pivot-Random...";

    test = sorting_test_1;
    quick_sort_2_pivots(test, 0, test.size(), random_two_pivot_paritiion);
    assert(test == sorting_solution_1);

    test = sorting_test_2;
    quick_sort_2_pivots(test, 0, test.size(), random_two_pivot_paritiion);
    assert(test == sorting_solution_2);

    cout << "passed." << endl;

#endif


    vector<vector<int>> inputs = generate_random_values(100000, 1000);
    vector<vector<int>> inputs_lomuto = inputs;
    vector<vector<int>> inputs_hoare = inputs;
    vector<vector<int>> inputs_median = inputs;

    cout << endl;
    cout << "Quick-Sort Results (average time in ns):" << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
    cout << "Lomuto: " 
        << get_total_time(lomuto_partition, inputs_lomuto) / 100000 << endl;
    cout << "Hoare: " 
        << get_total_time(hoare_partition, inputs_hoare) / 100000 << endl;
    cout << "Median: " 
        << get_total_time(median_partition, inputs_median) / 100000 << endl;
    cout << endl;

#ifndef DEBUG
    cout << "NOTE: For the two pivot partitions, please run this program as"
        << " debug (`make debug`)." << endl;
#endif



    return 0;
}

