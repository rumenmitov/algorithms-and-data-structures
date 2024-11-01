#ifndef __TIMER_H
#define __TIMER_H

/**
 * @brief Runs function with exponentially increasing inputs until time limit
 * has been reached.
 * 
 * @param unsigned long long (*)(unsigned long long)    Function to measure.
 * @param unsigned int time_limit    Time limit in microseconds.
 * 
 * @return unsigned long long
*/
unsigned long long measure(
        unsigned long long (*)(unsigned long long), 
        unsigned long long
        );



#endif
