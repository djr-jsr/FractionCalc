#include "Polynomial.hxx"
#include "Fraction.hxx"
#include <iostream>
#include <vector>

using namespace std;

Poly::Poly(unsigned int a) {
    degree_ = a;
    coefficients_.resize(a + 1);
}

Poly::Poly(const Poly& pol) {
    degree_ = pol.degree_;
    coefficients_ = pol.coefficients_;
}

Poly::~Poly() {

}

Poly& Poly::operator=(const Poly& pol) {
    degree_ = pol.degree_;
    coefficients_.resize(degree_);
    coefficients_ = pol.coefficients_;
    return (*this);
}

Poly Poly::operator+() {
    return (*this);
}

Poly Poly::operator-() {
    Poly p((*this).degree_);
    for (int i = 0; i < (*this).degree_ + 1; i++) {
        p.coefficients_[i] = -coefficients_[i];
    }
    return p;
}

Poly Poly::operator+(const Poly& pol) {
    int degree = 0;
    Poly p;
    if ((*this).degree_ < pol.degree_) {
        degree = (*this).degree_;
        p.degree_ = pol.degree_;
        p.coefficients_.resize(p.degree_ + 1);
        for (int i = 0; i < p.degree_ + 1; i++) {
            p.coefficients_[i] = pol.coefficients_[i];
        }
        for (int i = 0; i < degree + 1; i++) {
            p.coefficients_[i] = p.coefficients_[i] + coefficients_[i];
        }
    } else {
        degree = pol.degree_;
        p.degree_ = (*this).degree_;
        p.coefficients_.resize(p.degree_ + 1);
        for (int i = 0; i < p.degree_ + 1; i++) {
            p.coefficients_[i] = coefficients_[i];
        }

        for (int i = 0; i < degree + 1; i++) {
            p.coefficients_[i] = p.coefficients_[i] + pol.coefficients_[i];
        }
    }


    for (int i = p.degree_; i > 0; i--) {
        if (p.coefficients_[i] == 0) {
            p.coefficients_.pop_back();
            p.degree_--;
        } else
            break;
    }
    
    return p;
}

Poly Poly::operator-(const Poly& pol) {
    int degree = 0;
    Poly p;
    p = pol;
    p = -p;
    p = (*this) + p;
    return p;
}

Poly& Poly::operator+=(const Poly& pol) {
    (*this) = (*this) + pol;
    return (*this);
}

Poly& Poly::operator-=(const Poly& pol) {
    (*this) = (*this) - pol;
    return (*this);
}

ostream& operator<<(ostream& os, const Poly& p) {
    if (p.degree_ == 0) {
        os << "0" << " ";
    } else
        for (int i = p.degree_; i >= 0; i--) {
            if (p.coefficients_[i] != 0) {
                if (i == 0)
                    os << p.coefficients_[i] << " ";
                else if (i == 1)
                    os << p.coefficients_[i] << "x ";
                else
                    os << p.coefficients_[i] << "x^" << i << " ";
            }
        }
    return os;
}

istream& operator>>(istream& is, Poly& p) {
    for (int i = p.degree_; i >= 0; i--) {
        is >> p.coefficients_[i];
    }
    return is;
}

Fraction Poly::Evaluate(const Fraction& f) {
    Fraction sum = 0;
    for (int i = degree_; i >= 0; i--) {
        sum = sum * f + coefficients_[i];
    }
    return sum;
}