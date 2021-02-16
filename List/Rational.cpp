#include <iostream>
#include<cmath>
#include<algorithm>
#include <sstream>
#include<map>
#include<set>
#include<vector>
using namespace std;
int NOD(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    while (a > 0 && b > 0) {

        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }

    }
    return a + b;
}
int NOK(int a, int b) {
    int nok = a * b / NOD(a, b);
    return nok;
}
class Rational {
public:
    Rational() {
        numerat = 0;
        denominar = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw 1;
        }
        int  k = abs(NOD(numerator, denominator));
        numerat = numerator / k;
        denominar = denominator / k;
        if (denominar < 0 || (denominar < 0 && numerat < 0)) {
            denominar = -denominar;
            numerat = -numerat;
        }

        if (numerat == 0) {
            denominar = 1;
        }
    }

    int Numerator() const {
        return numerat;
    }

    int Denominator() const {
        return denominar;
    }

private:
    int numerat;
    int denominar;

};

bool operator == (const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator())) {
        return true;
    }
    return false;
}
Rational operator +(const Rational& lhs, const Rational& rhs) {

    int del = NOK(lhs.Denominator(), rhs.Denominator());
    int value1 = (del / lhs.Denominator()) * lhs.Numerator();
    int value2 = (del / rhs.Denominator()) * rhs.Numerator();
    Rational new_fraction((value1 + value2), del);
    return new_fraction;

}
Rational operator -(const Rational& lhs, const Rational& rhs) {
    int del = NOK(lhs.Denominator(), rhs.Denominator());
    int value1 = (del / lhs.Denominator()) * lhs.Numerator();
    int value2 = (del / rhs.Denominator()) * rhs.Numerator();
    Rational new_fraction((value1 - value2), del);
    return new_fraction;

}
Rational operator *(const Rational& lhs, const Rational& rhs) {
    Rational new_fraction((lhs.Numerator() * rhs.Numerator()), (lhs.Denominator() * rhs.Denominator()));
    return new_fraction;
}
Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw 2;
    }
    Rational new_fraction((lhs.Numerator() * rhs.Denominator()), (lhs.Denominator() * rhs.Numerator()));
    return new_fraction;
}
ostream& operator << (ostream& stream, const Rational& fraction) {
    stream << fraction.Numerator() << "/" << fraction.Denominator();
    return stream;
}
istream& operator>> (istream& stream, Rational& fraction) {
    int n = 0, m = 0;
    char ch;
    if (stream >> n && stream >> ch && ch == '/' && stream >> m) {
        fraction = { n, m };
    }

    return stream;
}
bool operator <(const Rational& lhs, const Rational& rhs) {
    int del = NOK(lhs.Denominator(), rhs.Denominator());
    int num1 = (del / lhs.Denominator()) * lhs.Numerator();
    int num2 = (del / rhs.Denominator()) * rhs.Numerator();
    if (num1 < num2)
        return true;
    return false;
}

int main() {
    try {
        char symbol;
        Rational fraction1;
        Rational fraction2;
        cin >> fraction1 >> symbol >> fraction2;
        
        if (symbol == '+') {
            cout << fraction1 + fraction2;
        }
        else if (symbol == '-') {
            cout << fraction1 - fraction2;
        }
        else if (symbol == '*') {
            cout << fraction1 * fraction2;
        }
        else
            cout << fraction1 / fraction2;
    }
    catch (int exep) {
        if (exep == 1) {
            cout << "Invalid argument";
        }
        else
            cout << "Division by zero";
    }
    return 0;
}