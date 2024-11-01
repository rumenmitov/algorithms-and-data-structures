#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <fstream>
#include <iostream>

// Complex class with method to comapare two instances
class Complex {
    private:
        double real;
        double imag;

    public:
        Complex();
        Complex(double, double);
        ~Complex();

        double getReal() const;
        double getImag() const;

        Complex operator=(const Complex&);

        bool operator==(const Complex&) const;
        friend std::ostream& operator<<(std::ostream&, const Complex& c);
};

#endif
