#include <chrono>
#include <cstdlib>
#include <ctime>
#include <deque>

#include "MergeSort.h"

std::deque<int> merge(std::deque<int>& left, std::deque<int>& right) {
    std::deque<int> res;

    size_t left_size = left.size();
    size_t right_size = right.size();

    for (size_t i = 0; i < left_size + right_size; i++) {
        if (left.empty()) {
            res.push_back(right.front());
            right.pop_front();
            continue;
        }

        if (right.empty()) {
            res.push_back(left.front());
            left.pop_front();
            continue;
        }

        if (left.front() < right.front()) {
            res.push_back(left.front());
            left.pop_front();
        } else {
            res.push_back(right.front());
            right.pop_front();
        }
    }

    return res;
}

void insertion_sort(std::deque<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];

        size_t j = i;

        while (j > 0 && arr[j - 1] > key) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[--j] = temp;
        }
        arr[j] = key;
    }
}


void merge_k_sort(std::deque<int>& arr, int k) {
    if (arr.size() <= static_cast<size_t>(k)) {
        return insertion_sort(arr);
    }

    size_t midpoint = arr.size() / 2;

    std::deque<int> left = 
        std::deque<int>(arr.begin(), arr.begin() + midpoint);

    std::deque<int> right = 
        std::deque<int>(arr.begin() + midpoint, arr.end());

    merge_k_sort(left, k);
    merge_k_sort(right, k);

    arr = merge(left, right);
    return;
}


std::deque<int> generate_input(int n) {
    std::deque<int> res;

    srand( time(nullptr) );

    for (int i = 0; i < n; i++) {
        res.push_back( rand() % 1000 + 1 );
    }

    return res;
}

size_t measure_sort(std::deque<int>& data, int k, bool multiple) {

    if (multiple) {
        std::deque<int> tmp1(data);
        std::deque<int> tmp2(data);
        std::deque<int> tmp3(data);

        merge_k_sort(tmp1, k);
        merge_k_sort(tmp2, k);
        merge_k_sort(tmp3, k);
    }

    using namespace std::chrono;

    auto start = steady_clock::now();
    merge_k_sort(data, k);
    auto stop = steady_clock::now();

    return duration_cast<microseconds>(stop - start).count();
}





