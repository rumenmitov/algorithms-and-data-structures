#pragma once

#include <vector>

#include "MaxHeap.h"

class LongestSubarray {

    public:
        LongestSubarray();

        // Starts from the back and creates subarrays for each element.
        // If the next element is smaller than the head of a subarray, the 
        // element is appended to the subarray.
        LongestSubarray(const std::vector<int>&);

        ~LongestSubarray();

       // Returns the longest subarray.
       const std::deque<int> get() const;

    private:
       MaxHeap subarrays;

};

