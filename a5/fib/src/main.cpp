#include <iostream>
#include <fstream>

#ifdef DEBUG
#include <cassert>
#endif

#include "Fibonacci.h"
#include "Timer.h"


#define TIME_PERIOD_TESTS 10


using namespace std;
int main(void) {

#ifdef DEBUG

    /* 
     * INFO:
     * According to https://en.wikipedia.org/wiki/Fibonacci_sequence
     * F_19 = 4181.
     */

    cout << "Testing naive_recursion...";
    assert(naive_recursive(0) == 0);
    assert(naive_recursive(1) == 1);
    assert(naive_recursive(2) == 1);
    assert(naive_recursive(5) == 5);
    assert(naive_recursive(19) == 4181);
    cout << "passed" << endl;

    cout << "Testing bottom_up...";
    assert(bottom_up(0) == 0);
    assert(bottom_up(1) == 1);
    assert(bottom_up(2) == 1);
    assert(bottom_up(5) == 5);
    assert(bottom_up(19) == 4181);
    cout << "passed" << endl;

    cout << "Testing closed_form...";
    assert(closed_form(0) == 0);
    assert(closed_form(1) == 1);
    assert(closed_form(2) == 1);
    assert(closed_form(5) == 5);
    assert(closed_form(19) == 4181);
    cout << "passed" << endl;

    cout << "Testing matrix...";
    assert(matrix(0) == 0);
    assert(matrix(1) == 1);
    assert(matrix(2) == 1);
    assert(matrix(5) == 5);
    assert(matrix(19) == 4181);
    cout << "passed" << endl;

#endif


    ofstream results("build/results.txt");
    ofstream f_naive("build/results_naive_recursive.txt");
    ofstream f_bottom_up("build/results_bottom_up.txt");
    ofstream f_closed_form("build/results_closed_form.txt");
    ofstream f_matrix("build/results_matrix.txt");

    const int TIME_PERIODS[TIME_PERIOD_TESTS] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    results << "Naive recursive:\n";
    for (int i = 0; i < TIME_PERIOD_TESTS; i++) {
        unsigned long long time = measure(naive_recursive, TIME_PERIODS[i]);
        results 
            << "\t" 
            << TIME_PERIODS[i] 
            << "µs - " 
            << time
            << endl;

        f_naive << TIME_PERIODS[i] << "\t" << time << endl;
    }

    results << endl;

    results << "Bottom-up:\n";
    for (int i = 0; i < TIME_PERIOD_TESTS; i++) {
        unsigned long long time = measure(bottom_up, TIME_PERIODS[i]);
        results 
            << "\t" 
            << TIME_PERIODS[i] 
            << "µs - " 
            << time 
            << endl;

        f_bottom_up << TIME_PERIODS[i] << "\t" << time << endl;
    }

    results << endl;

    results << "Closed form:\n";
    for (int i = 0; i < TIME_PERIOD_TESTS; i++) {
        unsigned long long time = measure(closed_form, TIME_PERIODS[i]);
        results 
            << "\t" 
            << TIME_PERIODS[i] 
            << "µs - " 
            << time
            << endl;

        f_closed_form << TIME_PERIODS[i] << "\t" << time << endl;
    }

    results << endl;

    results << "Matrices:\n";
    for (int i = 0; i < TIME_PERIOD_TESTS; i++) {
        unsigned long long time = measure(matrix, TIME_PERIODS[i]);
        results 
            << "\t" 
            << TIME_PERIODS[i] 
            << "µs - " 
            << time
            << endl;

        f_matrix << TIME_PERIODS[i] << "\t" << time << endl;
    }

    results.close();
    f_naive.close();
    f_bottom_up.close();
    f_closed_form.close();
    f_matrix.close();


    return 0;
}
