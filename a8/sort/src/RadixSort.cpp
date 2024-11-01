#include <vector>

#include "RadixSort.h"
#include "CountSort.h"


std::vector<std::string> radix_sort(
        const std::vector<std::string>& arr, 
        unsigned int k) 
{
    std::vector<std::string> res = arr;

    while (k > 0) {
        res = count_sort_nth_byte(res, --k, 0, res.size());
    }

    return res;
}

std::vector<std::string> hollerith_radix_sort(
        const std::vector<std::string>& arr, 
        unsigned int k,
        unsigned int lo,
        unsigned int hi) 
{
    // INFO: Inspired by: https://en.wikipedia.org/wiki/Radix_sort

    if (arr.empty()) return std::vector<std::string>();                      
    if (hi - lo < 2) return std::vector<std::string> { arr[lo] };                

    if (k >= arr[0].size() ) return std::vector<std::string>();                     

    std::vector<std::string> res;                                                     
    std::vector<std::string> k_th_char_sorted = count_sort_nth_byte(arr, k, lo, hi);     


    char current = k_th_char_sorted[lo][k];                                                 
    for (unsigned int i = lo + 1; i < k_th_char_sorted.size(); i++) {                          
        if (k_th_char_sorted[i][k] > current) {
            for (auto str : hollerith_radix_sort(k_th_char_sorted, k + 1, lo, i)) {                  
                res.push_back(str);                                                                    
            }

            current = k_th_char_sorted[i][k];                                                            
            lo = i;                                                                                        
        }
    }

    if (res.size() < arr.size()) {
        for (auto str : hollerith_radix_sort(k_th_char_sorted, k + 1, lo, hi)) {                            
            res.push_back(str);
        }

    }

    return res;
}
