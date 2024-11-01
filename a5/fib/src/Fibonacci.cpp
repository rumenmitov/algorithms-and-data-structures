#include <cassert>
#include <cmath>

#include "Fibonacci.h"

unsigned long long naive_recursive
    (unsigned long long n) {

    if (n == 0 || n == 1) return n;

    return naive_recursive(n - 1) + naive_recursive(n - 2);
}

unsigned long long bottom_up(unsigned long long n) {
    if (n == 0) return 0;

    unsigned long long prev = 0;
    unsigned long long res = 1;

    for (unsigned long long i = 1; i < n; i = i + 1) {
        const unsigned long long temp = res;
        res = res + prev;
        prev = temp;
    }

    return res;
}

unsigned long long closed_form(unsigned long long n) {
    if (n < 2) return  n;
    if (n == 2) return 1;

    const double PHI = (1 + sqrt(5.0)) / 2.0;

    return ceil( pow(PHI, n) / sqrt(5.0) );
}


unsigned long long matrix(unsigned long long n) {

    if (n == 0 || n == 1) return n;

    return matrix_pow(n)[0][1];
}


unsigned long long** matrix_pow(unsigned long long n) {
    // NOTE: matrix function will handle case n == 0
    assert(n > 0);

    unsigned long long** res = new unsigned long long*[2];
    unsigned long long* row1 = new unsigned long long[2];
    unsigned long long* row2 = new unsigned long long[2];

    // Base Cases
    if (n == 1) {
        row1[0] = MATRIX[0][0];
        row1[1] = MATRIX[0][1];
        row2[0] = MATRIX[1][0];
        row2[1] = MATRIX[1][1];

        res[0] = row1;
        res[1] = row2;

        return res;
    }

    if (n == 2) {

        row1[0] = MATRIX[0][0] * MATRIX[0][0] 
            + MATRIX[0][1] * MATRIX[1][0];

        row1[1] = MATRIX[0][0] * MATRIX[0][1]
            + MATRIX[0][1] * MATRIX[1][1];

        row2[0] = MATRIX[1][0] * MATRIX[0][0]
            + MATRIX[1][1] * MATRIX[1][0];

        row2[1] = MATRIX[1][0] * MATRIX[0][1]
            + MATRIX[1][1] * MATRIX[1][1];

        res[0] = row1;
        res[1] = row2;

        return res;
    }

    // Recursion Case
    unsigned long long** prev = matrix_pow((n - 1));

    row1[0] = prev[0][0] * MATRIX[0][0] 
        + prev[1][0] * MATRIX[0][1];

    row1[1] = prev[0][1] * MATRIX[0][0]
        + prev[1][1] * MATRIX[0][1];

    row2[0] = prev[0][0] * MATRIX[1][0]
        + prev[1][0] * MATRIX[1][1];

    row2[1] = prev[0][1] * MATRIX[1][0]
        + prev[1][1] * MATRIX[1][1];

    res[0] = row1;
    res[1] = row2;

    return res;
}
