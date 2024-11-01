#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H

#include <utility>
#include <vector>

/**
 * @brief Quick sort using a specified partitioning function.
 * 
 * @param std::vector<int>&
 * @param int (*)(std::vector<int>&, int, int)
 * 
 * @return void
*/
void quick_sort(
        std::vector<int>&, 
        int, 
        int, 
        int (*)(std::vector<int>&, int, int));



/**
 * @brief Quick sort using a specified 2-pivot partitioning function.
 * 
 * @param std::vector<int>&
 * @param std::pair<int, int> (*)(std::vector<int>&, int, int)
 * 
 * @return void
*/
void quick_sort_2_pivots(
        std::vector<int>&, 
        int, 
        int, 
        std::pair<int, int> (*)(std::vector<int>&, int, int));



#endif
