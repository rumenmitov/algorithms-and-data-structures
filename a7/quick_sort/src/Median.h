#ifndef __MEDIAN_H
#define __MEDIAN_H

#include <vector>

/**
 * @brief Paritions array using median of three.
 * 
 * @param std::vector<int>& arr
 * @param int lo Inclusive.
 * @param int hi Not inclusive.
 * 
 * @return int
*/
int median_partition(std::vector<int>&, int, int);

#endif
