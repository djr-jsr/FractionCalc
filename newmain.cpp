#include <iostream>
using namespace std;

#include "Fraction.hxx"
#include "Polynomial.hxx"

void TestFraction() {
    cout << "\nTest Fraction Data Type" << endl;

    // CONSTRUCTORS
    // ------------
    Fraction f1(5, 3);
    Fraction f2(7.2);
    Fraction f3;

    cout << "Fraction f1(5, 3) = " << f1 << endl;
    cout << "Fraction f2(7.2) = " << f2 << endl;
    cout << "Fraction f3 = " << f3 << endl;

    // BASIC ASSIGNEMENT OPERATOR
    // --------------------------
    // Fraction& operator=(const Fraction&);
    cout << "Assingment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = f1;
    cout << "Assingment (After): f3 = " << f3 << ". f1 = " << f1 << endl;

    f3 = Fraction::sc_fUnity;

    // UNARY ARITHMETIC OPERATORS
    // --------------------------
    // Fraction operator-();		// Operand 'this' implicit
    f3 = -f1;
    cout << "Unary Minus: f3 = " << f3 << ". f1 = " << f1 << endl;

    // Fraction operator+();

    // Fraction operator--();		// Pre-decrement. Dividendo
    f3 = Fraction::sc_fUnity;
    cout << "Pre-Decrement (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = --f1;
    cout << "Pre-Decrement (After): f3 = " << f3 << ". f1 = " << f1 << endl;

    // Fraction operator--(int);	// Post-decrement. Lazy Dividendo
    f3 = Fraction::sc_fUnity;
    cout << "Post-Decrement (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = f1--;
    cout << "Post-Decrement (After): f3 = " << f3 << ". f1 = " << f1 << endl;

    // Fraction operator++();		// Pre-increment. Componendo
    f3 = Fraction::sc_fUnity;
    cout << "Pre-Increment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = ++f1;
    cout << "Pre-Increment (After): f3 = " << f3 << ". f1 = " << f1 << endl;

    // Fraction operator++(int);	// Post-increment. Lazy Componendo
    f3 = Fraction::sc_fUnity;
    cout << "Post-Increment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = f1++;
    cout << "Post-Increment (After): f3 = " << f3 << ". f1 = " << f1 << endl;

    // BINARY ARITHMETIC OPERATORS USING FRIEND FUNCTIONS
    // --------------------------------------------------
    // friend Fraction operator+(const Fraction&, const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f1 + f2;
    cout << "Binary Plus: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // friend Fraction operator-(const Fraction&, const Fraction&);
    f1 = Fraction(16, 3);
    f2 = Fraction(22, 13);
    f3 = f1 - f2;
    cout << "Binary Minus: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // friend Fraction operator*(const Fraction&, const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(18, 25);
    f3 = f1 * f2;
    cout << "Multiply: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // friend Fraction operator/(const Fraction&, const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f1 / f2;
    cout << "Divide: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // friend Fraction operator%(const Fraction&, const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f1 % f2;
    cout << "Residue: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // BINARY RELATIONAL OPERATORS
    // ---------------------------
    // bool operator==(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    bool bTest = f1 == f2;
    cout << "Equal: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // bool operator!=(const Fraction&);
    bTest = f1 != f2;
    cout << "Not Equal: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // bool operator<(const Fraction&);
    bTest = f1 < f2;
    cout << "Less: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // bool operator<=(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = Fraction(5, 12);
    bTest = f1 <= f2;
    cout << "Less Equal: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f2 = " << f2 << endl;
    bTest = f1 <= f3;
    cout << "Less Equal: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f3 = " << f3 << endl;

    // bool operator>(const Fraction&);
    bTest = f1 > f2;
    cout << "Greater: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f2 = " << f2 << endl;

    // bool operator>=(const Fraction&);
    bTest = f1 >= f2;
    cout << "Greater Equal: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f2 = " << f2 << endl;
    bTest = f1 >= f3;
    cout << "Greater Equal: Test = " << ((bTest) ? "true" : "false") << ". f1 = " << f1 << ". f3 = " << f3 << endl;

    // ADVANCED ASSIGNEMENT OPERATORS
    // ------------------------------
    // Fraction& operator+=(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f2;
    f2 += f1;
    cout << "+=: f2 = " << f2 << ". f1 = " << f1 << ". f2 (before) = " << f3 << endl;
    f3 = f2;
    f2 += f2;
    cout << "+=: f2 = " << f2 << ". f2 (before) = " << f3 << endl;

    // Fraction& operator-=(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f2;
    f2 -= f1;
    cout << "-=: f2 = " << f2 << ". f1 = " << f1 << ". f2 (before) = " << f3 << endl;
    f3 = f2;
    f2 -= f2;
    cout << "-=: f2 = " << f2 << ". f2 (before) = " << f3 << endl;

    // Fraction& operator*=(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f2;
    f2 *= f1;
    cout << "*=: f2 = " << f2 << ". f1 = " << f1 << ". f2 (before) = " << f3 << endl;
    f3 = f2;
    f2 *= f2;
    cout << "*=: f2 = " << f2 << ". f2 (before) = " << f3 << endl;

    // Fraction& operator/=(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f2;
    f2 /= f1;
    cout << "/=: f2 = " << f2 << ". f1 = " << f1 << ". f2 (before) = " << f3 << endl;
    f3 = f2;
    f2 /= f2;
    cout << "/=: f2 = " << f2 << ". f2 (before) = " << f3 << endl;

    // Fraction& operator%=(const Fraction&);
    f1 = Fraction(7, 18);
    f2 = Fraction(5, 12);
    f3 = f2;
    f2 %= f1;
    cout << "%=: f2 = " << f2 << ". f1 = " << f1 << ". f2 (before) = " << f3 << endl;
    f3 = f2;
    f2 %= f2;
    cout << "%=: f2 = " << f2 << ". f2 (before) = " << f3 << endl;

    return;
}

void TestPoly() {
    cout << "\nTest Poly Data Type" << endl;
    // Polynomial with int value and int coefficients
    Poly p(10);
    cout << "Input Poly: p(x)" << endl;
    cin >> p;
    cout << "\np(x) = " << p << endl;
    Fraction f;
    cout << "Input Fraction" << endl;
    cin >> f;
    cout << "p(" << f << ") = " << p.Evaluate(f) << endl;
    Poly q = p;
    cout << "Copied Polynomial: " << q << endl;
    Poly r;
    r = p;
    cout << "Assigned Polynomial: " << r << endl;
    r = -p;
    cout << "Negated Polynomial -p(x) = " << r << endl;
    cout << "Input Poly<int, int>: q(x)" << endl;
    cin >> q;
    cout << "\nq(x) = " << q << endl;
    cout << "\np(x) = " << p << endl;
    r = p + q;
    cout << "p(x) + q(x) = " << r << endl;
    r = p - q;
    cout << "p(x) - q(x) = " << r << endl;
    p += q;
    cout << "p(x) <-- p(x) + q(x): " << p << endl;
    q -= p;
    cout << "q(x) <-- q(x) - p(x): " << q << endl;
}

void FractionCalc() {
    cout << "Welcome to my fraction calculator\n";
    while (1) {
        Fraction a, b, ans;
        cout << "Enter two fractions:\n";
        cin >> a;
        cin >> b;
        cout << "1.Add 2.Subtract 3.Multiply 4.Divide 5.Exit\n";
        int i;
        cin >> i;
        switch (i) {
            case 1: ans = a + b;
                break;
            case 2: ans = a - b;
                break;
            case 3: ans = a*b;
                break;
            case 4: ans = a / b;
                break;
            case 5: return;
                break;
            default: cout << "Wrong Input\n";
                continue;
        }
        cout << "The answer is " << ans << endl;
    }
}

int main() {
    TestFraction();
    TestPoly();
    FractionCalc();
    return 0;
}