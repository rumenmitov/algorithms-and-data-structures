#include "LongestSubarray.h"

LongestSubarray::LongestSubarray() {}

LongestSubarray::LongestSubarray(const std::vector<int> &v) {
  for (auto crit = v.crbegin(); crit != v.crend(); crit++) {
    for (size_t i = 1; i < subarrays.heap.size(); i++) {
      if (*crit < subarrays.heap[i][0]) {
        subarrays.heap[i].push_front(*crit);
        subarrays.heapify_up(i);
      }
    }

    subarrays.insert(std::deque<int>{*crit});
  }
}

LongestSubarray::~LongestSubarray() {}

const std::deque<int> LongestSubarray::get() const { return subarrays.peek(); }
