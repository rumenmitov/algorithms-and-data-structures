#include <vector>

#include "BucketSort.h"
#include "Utils.h"

std::vector<float> bucket_sort(const std::vector<float>& arr) {
    std::vector<std::vector<float>> buckets;

    for (size_t i = 0; i < arr.size(); i++) 
        buckets.push_back(std::vector<float>());

    float max = find_max_element(arr) + 1;

    for (float x : arr) {
        buckets[ static_cast<int>( x * arr.size() / max ) ].push_back(x);
    }

    for (size_t i = 0; i < buckets.size(); i++) {
        insertion_sort(buckets[i]);
    }

    std::vector<float> output;

    for (size_t i = 0; i < buckets.size(); i++) {
        for (float x : buckets[i]) output.push_back(x);
    }

    return output;
}
