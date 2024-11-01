#include <iostream>

#include "complex.h"


// Generic linear search as we do not know if array is sorted
template<class T>
int array_search(const T* array, const unsigned int len, const T& needle) {
    for (unsigned int i = 0; i < len; ++i) {
        if (array[i] == needle) return i;
    }

    return -1;
}


#define ARR_SIZE 5

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 1.1 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    // Integer test
    const int i_arr[ARR_SIZE] = {1, 2, 3, 4, 5};

    cout << "Integer array:\n[ ";
    for (int i : i_arr) {
        cout << i << " ";
    }
    cout << "]\n";

    const int i_needle = 5;
    cout << "Looking for: " << i_needle << endl;
    cout << "Index: " << array_search(i_arr, ARR_SIZE, i_needle) << endl 
        << endl;


    // Double test
    const double d_arr[ARR_SIZE] = {1.0, 3.0, 5.0, 2.3, -1.3};

    cout << "Double array:\n[ ";
    for (double d : d_arr) {
        cout << d << " ";
    }
    cout << "]\n";

    const double d_needle = 3.9;
    cout << "Looking for: " << d_needle << endl;
    cout << "Index: " << array_search(d_arr, ARR_SIZE, d_needle) << endl 
        << endl;


    // Complex test
    const Complex c_arr[ARR_SIZE] = {
        Complex(), 
        Complex(1, -2), 
        Complex(3, 4),
        Complex(-1, -1), 
        Complex(1.2, -3.4)
    };

    cout << "Complex array:\n[ ";
    for (Complex c : c_arr) {
        cout << c << " ";
    }
    cout << "]\n";

    const Complex c_needle = Complex(3, 4);
    cout << "Looking for: " << c_needle << endl;
    cout << "Index: " << array_search(c_arr, ARR_SIZE, c_needle) << endl 
        << endl;

}
