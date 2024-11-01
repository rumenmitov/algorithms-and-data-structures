#ifndef __RESULTS_H
#define __RESULTS_H

#include <cstdlib>
#include <ctime>
#include <utility>
#include <chrono>
#include <vector>

#include "Heap.h"


/**
 * @brief Calculates the time taken for top-down and bottom-up heap sort.
*/
class Results {

    public:
        // Constructors
        Results();

        // Calculates time for heap with input size n.
        Results(int);


        // Default destructor
        ~Results();


        // Returns time for top-down heap-sort in microseconds
        unsigned long long top_down_time();


        // Returns time for bottom-up heap-sort in microseconds
        unsigned long long bottom_up_time();


    private:
        std::vector<int> input;
        std::pair<unsigned long long, unsigned long long> time_taken;

};


#endif
