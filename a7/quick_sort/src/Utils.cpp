#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "QuickSort.h"
#include "Utils.h"


std::vector<std::vector<int>> generate_random_values(
        unsigned long long N,
        unsigned long long M) 

{
    std::vector<std::vector<int>> res;
    srand(time(nullptr));

    for (unsigned long long i = 0; i < N; i++) {
        std::vector<int> sequence;

        for (unsigned long long j = 0; j < M; j++) 
            sequence.push_back(rand() % 1000 + 1);

        res.push_back(sequence);
    }

    return res;
}


size_t get_total_time(
        int (*partition)(std::vector<int>&, int, int),
        std::vector<std::vector<int>>& inputs) 

{
    using namespace std::chrono;
    auto start = steady_clock().now();

    for (std::vector<int> sequence : inputs) {
        quick_sort(sequence, 0, sequence.size(), partition);
    }

    auto stop = steady_clock().now();

    return duration_cast<nanoseconds>(stop - start).count();
}

