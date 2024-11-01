#ifndef __RADIX_SORT_H
#define __RADIX_SORT_H

#include <string>
#include <vector>


/*
 * @brief Sorts sequence of strings with uniform length k.
 *
 * @param const std::vector<std::string>&
 * @param unsigned int
 *
 * @returns std::vector<std::string>
 */
std::vector<std::string> radix_sort(
        const std::vector<std::string>&, 
        unsigned int);

/*
 * @brief Sorts sequence of strings in range lo to hi at character lo 
 *        using Hoolertith' version of radix sort.
 *
 * @param const std::vector<std::string>&
 * @param unsigned int
 * @param unsigned int
 *
 * @returns std::vector<std::string>
 */
std::vector<std::string> hollerith_radix_sort(
        const std::vector<std::string>&, 
        unsigned int,
        unsigned int,
        unsigned int);

#endif
