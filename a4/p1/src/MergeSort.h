#ifndef __MERGESORT_H
#define __MERGESORT_H

#include <deque>

/**
 * @brief Merges left and right deques, returning the resulting deque.
 * 
 * @param std::deque<int>& left
 * @param std::deque<int>& right
 * 
 * @return std::deque<int>
*/
std::deque<int> merge(std::deque<int>& left, std::deque<int>& right);

/**
 * @brief Sorts deque using insertion sort.
 * 
 * @param std::deque<int>& arr
 * 
 * @return void
*/
void insertion_sort(std::deque<int>& arr);


/**
 * @brief Divides into sub-arrays of length k, then applies Insertion Sort.
 * 
 * @param const std::deque<int>& arr
 * @param int k
 * 
 * @return void
*/
void merge_k_sort(std::deque<int>& arr, int k);


/**
 * @brief Returns an unsorted deque of size n with elements from 1 to 1000.
 * 
 * @param int n
 * 
 * @return std::deque<int>
*/
std::deque<int> generate_input(int n);


/**
 * @brief Measures the time taken (in microseconds) to execute the 
 *        custom merge sort with a given k.
 * 
 * @param std::deque<int>& data
 * @param int k
 * @param bool multiple
 * 
 * @return size_t
*/
size_t measure_sort(std::deque<int>& data, int k, bool multiple);



#endif
