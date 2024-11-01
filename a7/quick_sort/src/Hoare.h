#ifndef __HOARE_H
#define __HOARE_H

#include <vector>

/**
 * @brief Hoare paritining of array.
 * 
 * @param std::vector<int>& arr
 * @param int lo Inclusive.
 * @param int hi Not inclusive.
 * 
 * @return int
*/
int hoare_partition(std::vector<int>&, int, int);

#endif
