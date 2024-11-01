#ifndef __UTILS_H
#define __UTILS_H

#include <vector>

/**
 * @brief Generates N sequences of size M, where each element is between
 * 1 and 1000.
 * 
 * @param unsigned long long N
 * @param unsigned long long M
 * 
 * @return std::vector<std::vector<int>>
*/
std::vector<std::vector<int>> generate_random_values(
        unsigned long long,
        unsigned long long);


/**
 * @brief Measures total time in nanoseconds for 
 * the given Quick-Sort partition to sort all inputs.
 * 
 * @param int (*)(std::vector<int>&, int, int)
 * @param std::vector<std::vector<int>>
 * 
 * @return size_t
*/
size_t get_total_time(
        int (*)(std::vector<int>&, int, int),
        std::vector<std::vector<int>>&);


#endif
