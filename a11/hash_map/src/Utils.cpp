#include <cmath>

#include "Utils.h"


bool is_prime(unsigned int n) {
    for (int i = 2; i < (int) sqrt( (double) n ); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

