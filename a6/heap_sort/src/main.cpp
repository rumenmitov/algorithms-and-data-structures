#include <cstdio>
#include <fstream>

#ifdef DEBUG
#include <iostream>
#include <vector>
#include <cassert>

#include "Heap.h"
#endif

#include "Results.h"


using namespace std;

int main(int argc, char* argv[]) {

#ifdef DEBUG

    cout << "Testing heap insertion...";
    MaxHeap insertion_solution = MaxHeap(vector<int>{4, 3, 2, 1});
    MaxHeap insertion_heap;
    insertion_heap.insert(1);
    insertion_heap.insert(2);
    insertion_heap.insert(4);
    insertion_heap.insert(3);
    assert(insertion_heap == insertion_solution);
    cout << "passed.\n";

    cout << "Testing heap-sort...";
    vector<int> sorted_solution_1 = vector<int>{0, -2, 0, 1, 1, 2, 3};
    MaxHeap sorting_heap_1(vector<int>{1, -2, 3, 0, 2, 1});
    sorting_heap_1.sort();
    assert(sorting_heap_1.get_heap() == sorted_solution_1);

    MaxHeap sorted_solution_2 = MaxHeap(vector<int>{});
    MaxHeap sorting_heap_2;
    sorting_heap_2.sort();
    assert(sorting_heap_2 == sorted_solution_2);
    cout << "passed.\n";

    cout << "Testing bottom-up heap-sort...";
    vector<int> sorted_solution_3 = vector<int>{0, -2, 0, 1, 1, 2, 3};
    MaxHeap sorting_heap_3(vector<int>{1, -2, 3, 0, 2, 1});
    sorting_heap_3.bottom_up_sort();
    assert(sorting_heap_3.get_heap() == sorted_solution_3);

    MaxHeap sorted_solution_4 = MaxHeap(vector<int>{});
    MaxHeap sorting_heap_4;
    sorting_heap_4.bottom_up_sort();
    assert(sorting_heap_4 == sorted_solution_4);
    cout << "passed.\n";
    
#endif

    ofstream top_down_results("build/results_top_down.txt");
    ofstream bottom_up_results("build/results_bottom_up.txt");
    
    int number_of_max_inputs = 100;

    if (argc > 1) {
        number_of_max_inputs = atoi(argv[1]);
    }

    for (int i = 0; i < number_of_max_inputs; i++) {
        Results res(i);

        char top_down_str[100];
        sprintf(top_down_str, "%-9d %lli\n", i, res.top_down_time());

        char bottom_up_str[100];
        sprintf(bottom_up_str, "%-9d %lli\n", i, res.bottom_up_time());

        top_down_results << top_down_str;
        bottom_up_results << bottom_up_str;
    }

    top_down_results.close();
    bottom_up_results.close();

    return 0;
}
