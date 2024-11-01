#ifndef __UTILS_H
#define __UTILS_H

#include <vector>
#include <iostream>

template <class T>
std::ostream& operator<<(std::ostream&, const std::vector<T>&);

// Returns the largest element in the list.
template <class T>
T find_max_element(const std::vector<T>&);

template <class T>
void insertion_sort(std::vector<T>&);


#endif
