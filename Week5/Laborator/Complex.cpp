#include "Complex.h"

bool double_equals(double l, double r)
{
    return abs(l - r) < 0.001;
}

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::GetReal_Data() const
{
    return this->real_data;
}

double Complex::GetImag_Data() const
{
    return this->imag_data;
}



double Complex::real() const
{
    return real_data;
}

double Complex::imag() const
{
    return imag_data;
}

double Complex::abs() const
{
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const
{
    return { real(), -imag() };
}

Complex& Complex::operator++()
{
    real_data++;
    return *this;
}

Complex& Complex::operator--()
{
    real_data--;
    return *this;
}

Complex operator+(const Complex& l, const Complex& r)
{
  return {l.GetReal_Data() + r.GetReal_Data(), l.GetImag_Data() + r.GetImag_Data()};
}

Complex operator-(const Complex& l, const Complex& r)
{
    return  { l.GetReal_Data() - r.GetReal_Data(), l.GetImag_Data() - r.GetImag_Data() };
}

Complex operator*(const Complex& l, const Complex& r)
{
    return { l.GetReal_Data() * r.GetReal_Data(), l.GetImag_Data() * r.GetImag_Data() };
}

Complex operator+(const Complex& l, double r)
{
    return { l.GetReal_Data() + (int)r, l.GetImag_Data() + r-floor(r)};
}

Complex operator+(double l, const Complex& r)
{
    return { r.GetReal_Data() + (int) l, r.GetImag_Data() + l - floor(l)};
}

Complex operator-(const Complex& obj)
{
    return {-1*obj.GetReal_Data(), obj.GetImag_Data()};
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.GetReal_Data() != r.GetReal_Data())
        return false;
    else
        if (l.GetImag_Data() != r.GetImag_Data())
            return false;
    return true;
}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);
}

