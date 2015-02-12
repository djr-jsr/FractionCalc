#ifndef __POLYNOMIAL_HXX	// Control inclusion of header files
#define __POLYNOMIAL_HXX

/************ C++ Headers ************************************/
#include <iostream>	// Defines istream & ostream for IO
#include <vector>
using namespace std;

class Poly {
public:
    // CONSTRUCTORS
    Poly(unsigned int = 0); // Uses default parameters.
    Poly(const Poly&); // Copy Constructor
    // DESTRUCTOR

    ~Poly(); // No virtual destructor needed


    // BASIC ASSIGNMENT OPERATOR
    Poly& operator=(const Poly&);


    // UNARY ARITHMETIC OPERATORS
    Poly operator-(); // Operand 'this' implicit
    Poly operator+();


    // BINARY ARITHMETIC OPERATORS
    Poly operator+(const Poly&);
    Poly operator-(const Poly&);


    // ADVANCED ASSIGNMENT OPERATORS
    Poly& operator+=(const Poly&);
    Poly& operator-=(const Poly&);


    // BASIC I/O using FRIEND FUNCTIONS
    friend ostream& operator<<(ostream& os, const Poly& p);
    friend istream& operator>>(istream& is, Poly& p);


    // METHODS
    Fraction Evaluate(const Fraction&); // Evaluates the polynomial - use Horner's Rule
private:
    // DATA MEMBERS
    unsigned int degree_;
    vector<int> coefficients_;
};

#include "Polynomial.inl"

#endif // __POLYNOMIAL_HXX