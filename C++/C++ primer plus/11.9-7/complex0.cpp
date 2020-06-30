#include "complex0.h"

complex::complex(double x, double y)
{
    real = x;
    imagin = y;
}
void complex::reset(double x, double y)
{
    real = x;
    imagin = y;
}
complex complex::operator+(const complex& m)
{
    complex result(real + m.real, imagin + m.imagin);
    return result;
}
complex complex::operator-(const complex& m)
{
    complex result(real - m.real, imagin - m.imagin);
    return result;
}
complex complex::operator*(const complex& m)
{
    complex result(real * m.real - imagin * m.imagin, real * m.imagin + imagin * m.real);
    return result;
}
complex complex::operator*(double n)
{
    complex result(real * n, imagin * n);
    return result;
}
complex operator*(double n, complex& m)
{
    return m * n;
}
complex complex::operator~()
{
    complex result(real, -imagin);
    return result;
}

ostream& operator<<(ostream& os, const complex& m)
{
    os << "(" << m.real << ", " << m.imagin << "i)";
    return os;
}
istream& operator>>(istream& is, complex& m)
{
    using std::cout;
    cout << "real: ";
    if (is >> m.real) {
        cout << "imaginary: ";
        is >> m.imagin;
    }    return is;
}