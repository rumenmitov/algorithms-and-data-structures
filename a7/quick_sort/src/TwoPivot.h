#ifndef __TWO_PIVOT_H
#define __TWO_PIVOT_H

#include <utility>
#include <vector>


/**
 * @brief Returns two partitions of array (pivots start as first two elements).
 *
 * @param std::vector<int>& arr
 * @param int lo Inclusive.
 * @param int hi Not inclusive.
 * 
 * @return std::pair<int, int>
*/
std::pair<int, int> two_pivot_partition
    (std::vector<int>&, int, int);



/**
 * @brief Returns two partitions of array (using random partitioning).
 *
 * @param std::vector<int>& arr
 * @param int lo Inclusive.
 * @param int hi Not inclusive.
 * 
 * @return std::pair<int, int>
*/
std::pair<int, int> random_two_pivot_paritiion
    (std::vector<int>&, int, int);



#endif
