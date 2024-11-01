#include <cstring>
#include <vector>

#include "CountSort.h"
#include "Utils.h"


std::vector<int> count_sort(const std::vector<int>& arr) {
    int helper_size = find_max_element(arr) + 1;

    if (helper_size == 0) return std::vector<int>();

    int* helper = new int[helper_size];
    memset(helper, 0, helper_size);

    for (int x : arr) helper[x]++;

    for (int i = 1; i < helper_size; i++) helper[i] += helper[i-1];

    std::vector<int> res(arr.size());

    for (auto rit = arr.crbegin(); rit != arr.crend(); rit++) {
        res[ helper[*rit] - 1 ] = *rit;
        helper[*rit]--;
    }

    return res;
}


std::vector<std::string> count_sort_nth_byte(
        const std::vector<std::string>& arr,
        int n,
        int lo,
        int hi
        )
{
    if (arr.empty()) return std::vector<std::string>();
    if (hi - lo < 2) return std::vector<std::string> { arr[lo] };
    if (hi - lo == 2) {
        std::vector<std::string> res = arr;
        if (res[lo] > res[lo + 1]) std::swap(res[lo], res[lo + 1]);
        return res;
    }


    std::vector<int> arr_nth_byte;
    for (int i = lo; i < hi; i++) arr_nth_byte.push_back( (int) arr[i][n] );


    int helper_size = find_max_element(arr_nth_byte) + 1;

    if (helper_size == 0) return std::vector<std::string>();

    int* helper = new int[helper_size];
    memset(helper, 0, helper_size);

    for (int x : arr_nth_byte) helper[x]++;

    for (int i = 1; i < helper_size; i++) helper[i] += helper[i-1];

    std::vector<std::string> res(hi - lo);


    for (int i = hi - 1; i >= lo; i--) {
        res[ helper[ (int) arr[i][n] ] - 1 ] = arr[i] ;
        helper[ (int) arr[i][n] ]--;
    }

    return res;
}


