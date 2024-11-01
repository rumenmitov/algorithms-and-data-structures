#ifndef __COUNT_SORT_H
#define __COUNT_SORT_H


#include <vector>
#include <string>


std::vector<int> count_sort(const std::vector<int>&);

/*
 * @brief Applies Count-Sort to the n-th byte from the lo-th index of the 
 *        subarray [lo, hi).
 *
 * @param const std::vector<std::string>&
 * @param int 
 * @param int 
 * @param int 
 *
 * @returns std::vector<std::string>
 *
 */
std::vector<std::string> count_sort_nth_byte(
        const std::vector<std::string>&, 
        int,
        int,
        int);


#endif
