#include "complex.h"

Complex::Complex() {
    real = imag = 0;
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::~Complex() {}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

Complex Complex::operator=(const Complex& c) {
    return Complex(c.real, c.imag);
}

bool Complex::operator==(const Complex& other) const {
    return (real == other.real && imag == other.imag);
}

std::ostream& operator<<(std::ostream& f, const Complex& c) {
    f << "(" << c.getReal() << ", "<< c.getImag() << ")";

    return f;
}
