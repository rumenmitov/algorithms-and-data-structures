#ifndef __FIBONACCI_H
#define __FIBONACCI_H

const unsigned long long MATRIX[2][2] = {
    {1, 1},
    {1, 0}
};

/**
 * @brief Fibonacci using recursion.
 * 
 * @param unsigned long long n    Starting from 0, specifies the n-th Fibonacci 
 * number.
 * 
 * @return unsigned long long
*/
unsigned long long naive_recursive(unsigned long long);

/**
 * @brief Fibonacci using bottom-up.
 * 
 * @param unsigned long long n    Starting from 0, specifies the n-th Fibonacci 
 * number.
 * 
 * @return unsigned long long
*/
unsigned long long bottom_up(unsigned long long);

/**
 * @brief Fibonacci using closed-form.
 * 
 * @param unsigned long long n    Starting from 0, specifies the n-th Fibonacci 
 * number.
 * 
 * @return unsigned long long
*/
unsigned long long closed_form(unsigned long long); 


/**
 * @brief Fibonacci using matrix representation.
 * 
 * @param unsigned long long n    Starting from 0, specifies the n-th Fibonacci 
 * number.
 * 
 * @return unsigned long long
*/
unsigned long long matrix(unsigned long long);

/**
 * @brief Calculates the n-th power of MATRIX.
 * 
 * @param unsigned long long n
 * 
 * @return unsigned long long**
*/
unsigned long long** matrix_pow(unsigned long long);


#endif
