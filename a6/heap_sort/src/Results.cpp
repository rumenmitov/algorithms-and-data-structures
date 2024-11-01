#include "Results.h"
#include "Heap.h"


Results::Results() { time_taken = std::make_pair(0, 0); }

Results::Results(int n) {
    for (int i = 0; i < n; i++) {
        srand(time(nullptr));

        input.push_back(rand() % 1000 + 1);
    }

    using namespace std::chrono;

    MaxHeap top_down_sorted(input);

    auto start = steady_clock().now();
    top_down_sorted.sort();
    auto stop = steady_clock().now();

    time_taken.first = 
        duration_cast<microseconds>(stop - start).count();


    MaxHeap bottom_up_sorted(input);

    start = steady_clock().now();
    bottom_up_sorted.bottom_up_sort();
    stop = steady_clock().now();

    time_taken.second = 
        duration_cast<microseconds>(stop - start).count();
}

Results::~Results() {}

unsigned long long Results::top_down_time() { return time_taken.first; }

unsigned long long Results::bottom_up_time() { return time_taken.second; }
