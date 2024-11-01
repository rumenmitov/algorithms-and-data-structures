#include "Utils.h"
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& f, const std::vector<T>& v) {
    for (T x : v) f << x << " ";

    return f;
}

template std::ostream& operator<<(std::ostream&, const std::vector<int>&);
template std::ostream& operator<<(std::ostream&, const std::vector<float>&);
template std::ostream& operator<<(std::ostream&, 
        const std::vector<std::string>&);


template <class T>
T find_max_element(const std::vector<T>& arr) {
    T max = 0;

    for (T x : arr) {
        if (x > max) max = x;
    }

    return max;
}

template int find_max_element<int>(const std::vector<int>&);
template float find_max_element<float>(const std::vector<float>&);


template <class T>
void insertion_sort(std::vector<T>& arr) {
    if (arr.size() < 2) return;

    for (size_t i = 1; i < arr.size(); i++) {
        T key = arr[i];

        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            j--;
            arr[j + 1] = arr[j];
        }
        arr[j] = key;
    }
}

template void insertion_sort<int>(std::vector<int>&);
template void insertion_sort<float>(std::vector<float>&);
