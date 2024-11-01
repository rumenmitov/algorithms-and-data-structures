#include <cmath>
#include <chrono>
#include <cstdint>

#include "Timer.h"

unsigned long long measure(
        unsigned long long (*func)(unsigned long long), 
        unsigned long long time_limit
        ) {

    unsigned long long total_time = 0;
    unsigned long long prev_input = 0;

    // INFO: Forever loop is intentional
    for (unsigned long long i = 0; i < INT64_MAX; i++) {

        // INFO: n rises slowly at first, but speeds up later on
        unsigned long long n = ceil(0.1 * i*i) + i;

        using namespace std::chrono;
        auto start = steady_clock::now();
        func(n);
        auto stop = steady_clock::now();

        total_time += duration_cast<microseconds>(stop - start).count();

        // INFO: If total time is exceeded return previous input
        if (total_time >= time_limit) return prev_input;

        prev_input = n;
    }

    return INT64_MAX;
}

