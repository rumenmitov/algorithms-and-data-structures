#ifndef __LOMUTO_H
#define __LOMUTO_H

#include <utility>
#include <vector>

/**
 * @brief Parititions according to Lomuto.
 * 
 * @param std::vector<int>& arr
 * @param int lo Inclusive.
 * @param int hi Not inclusive.
 * 
 * @return int
*/
int lomuto_partition(std::vector<int>& arr, int lo, int hi);


#endif
