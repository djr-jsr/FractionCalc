#include "Fraction.hxx"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

Fraction::Fraction(int a, int b) {
    iNumerator_ = a;
    uiDenominator_ = b;
    this->Normalize();
}

Fraction::Fraction(double fraction) {
    iNumerator_ = (int) precision() * fraction;
    uiDenominator_ = precision();
    this->Normalize();
}

Fraction::Fraction(const Fraction& fraction) {
    iNumerator_ = fraction.iNumerator_;
    uiDenominator_ = fraction.uiDenominator_;
}

Fraction::~Fraction() {

}

Fraction& Fraction::operator=(const Fraction& fraction) {
    iNumerator_ = fraction.iNumerator_;
    uiDenominator_ = fraction.uiDenominator_;
    return *this;
}

Fraction Fraction::operator-() {
    Fraction f;
    f.iNumerator_ = -1 * iNumerator_;
    f.uiDenominator_ = uiDenominator_;
    return f;
}

Fraction Fraction::operator+() {
    return *this;
}

Fraction& Fraction::operator--() {
    iNumerator_ = iNumerator_ - uiDenominator_;
    return *this;
}

Fraction& Fraction::operator++() {
    iNumerator_ = iNumerator_ + uiDenominator_;
    return *this;
}

Fraction Fraction::operator--(int numerator) {
    Fraction f = *this;
    iNumerator_ = iNumerator_ - uiDenominator_;
    return f;
}

Fraction Fraction::operator++(int numerator) {
    Fraction f = *this;
    iNumerator_ = iNumerator_ + uiDenominator_;
    return f;
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    Fraction f;
    unsigned int denominator = Fraction::lcm(f1.uiDenominator_, f2.uiDenominator_);
    f.iNumerator_ = denominator / f1.uiDenominator_ * f1.iNumerator_ + denominator / f2.uiDenominator_ * f2.iNumerator_;
    f.uiDenominator_ = denominator;
    f.Normalize();
    return f;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    Fraction f;
    unsigned int denominator = Fraction::lcm(f1.uiDenominator_, f2.uiDenominator_);
    f.iNumerator_ = denominator / f1.uiDenominator_ * f1.iNumerator_ - denominator / f2.uiDenominator_ * f2.iNumerator_;
    f.uiDenominator_ = denominator;
    f.Normalize();
    return f;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    Fraction f;
    f.iNumerator_ = f1.iNumerator_ * f2.iNumerator_;
    f.uiDenominator_ = f1.uiDenominator_ * f2.uiDenominator_;
    f.Normalize();
    return f;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    Fraction f;
    f.iNumerator_ = f1.iNumerator_ * f2.uiDenominator_;
    if (f2.iNumerator_ < 0) {
        f.iNumerator_ = -1 * f.iNumerator_;
        f.uiDenominator_ = f1.uiDenominator_ * (-1 * f2.iNumerator_);
    } else
        f.uiDenominator_ = f1.uiDenominator_ * f2.iNumerator_;
    f.Normalize();
    return f;
}

Fraction operator%(const Fraction& f1, const Fraction& f2) {
    Fraction f;
    f = f1 / f2;
    f.iNumerator_ = f.iNumerator_ % f.uiDenominator_;
    f = f * f2;
    f.Normalize();
    return f;
}

bool Fraction::operator==(const Fraction& f) {
    Fraction f_new;
    f_new = *this / f;
    if (f_new.iNumerator_ == f_new.uiDenominator_)
        return true;
    else
        return false;
}

bool Fraction::operator!=(const Fraction& f) {
    Fraction f_new;
    f_new = *this / f;
    if (f_new.iNumerator_ != f_new.uiDenominator_)
        return true;
    else
        return false;
}

bool Fraction::operator<(const Fraction& f) {
    unsigned int denominator = lcm((*this).uiDenominator_, f.uiDenominator_);
    if (denominator / (*this).uiDenominator_ * (*this).iNumerator_ < denominator / f.uiDenominator_ * f.iNumerator_)
        return true;
    else
        return false;
}

bool Fraction::operator<=(const Fraction& f) {
    unsigned int denominator = lcm((*this).uiDenominator_, f.uiDenominator_);
    if (denominator / (*this).uiDenominator_ * (*this).iNumerator_ <= denominator / f.uiDenominator_ * f.iNumerator_)
        return true;
    else
        return false;
}

bool Fraction::operator>(const Fraction& f) {
    unsigned int denominator = lcm((*this).uiDenominator_, f.uiDenominator_);
    if (denominator / (*this).uiDenominator_ * (*this).iNumerator_ > denominator / f.uiDenominator_ * f.iNumerator_)
        return true;
    else
        return false;
}

bool Fraction::operator>=(const Fraction& f) {
    unsigned int denominator = lcm((*this).uiDenominator_, f.uiDenominator_);
    if (denominator / (*this).uiDenominator_ * (*this).iNumerator_ >= denominator / f.uiDenominator_ * f.iNumerator_)
        return true;
    else
        return false;
}

Fraction& Fraction::operator+=(const Fraction& f) {
    (*this) = (*this) + f;
    return (*this);
}

Fraction& Fraction::operator-=(const Fraction& f) {
    (*this) = (*this) - f;
    return (*this);
}

Fraction& Fraction::operator*=(const Fraction& f) {
    (*this) = (*this) * f;
    return (*this);
}

Fraction& Fraction::operator/=(const Fraction& f) {
    (*this) = (*this) / f;
    return (*this);
}

Fraction& Fraction::operator%=(const Fraction& f) {
    (*this) = (*this) % f;
    return (*this);
}

Fraction Fraction::operator!() {
    int sign = 1;
    if ((*this).iNumerator_ < 0)
        sign = -1;
    int temp = (*this).iNumerator_;
    (*this).iNumerator_ = sign * (*this).uiDenominator_;
    (*this).uiDenominator_ = sign * temp;
    return (*this);
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.iNumerator_ << "/" << f.uiDenominator_;
    return out;
}

istream& operator>>(istream& in, Fraction& f) {
    char c;
    int num;
    unsigned int den;
    in >> num >> c;
    if (c == '/') {
        in >> den;
        if (den != 0) {
            Fraction f1(num, den);
            f = f1;
        } else {
            cout << "Can't divide by zero!!\n";
            Fraction f1(0, 1);
            f = f1;
            return in;
        }
    } else if (c == '.') {
        in >> den;
        std::ostringstream oss;
        oss << num << "." << den;
        string d = oss.str(); //atof(word.c_str())
        double dl = atof(d.c_str());
        Fraction f1(dl);
        f = f1;
    } else {
        Fraction f1(num);
        f = f1;
    }
    //in >> f.iNumerator_ >> c >> f.uiDenominator_;

    f.Normalize();
    return in;
}

int Fraction::gcd(int a, int b) {
    int c;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a == 0)
        return b;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int Fraction::lcm(int a, int b) {
    int c = gcd(a, b);
    return ((a * b) / c);
}

Fraction& Fraction::Normalize() {
    int sign = 1;
    if ((*this).iNumerator_ < 0)
        sign = -1;
    int hcf = gcd((*this).uiDenominator_, ((*this).iNumerator_ * sign));
    (*this).iNumerator_ = (*this).iNumerator_ / hcf;
    (*this).uiDenominator_ = (*this).uiDenominator_ / hcf;
    return (*this);
}

const Fraction Fraction::sc_fUnity = 1;
const Fraction Fraction::sc_fZero = 0;
