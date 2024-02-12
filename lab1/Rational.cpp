#include "Rational.h"
using namespace std;

// Given utility functions
// Return the greatest common denominator
int get_gcd(int a, int b) {
    a = (a<0)? (-a):a;
    b = (b<0)? (-b):b;
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    int result = ((a>b)? b:a);
    while(result>0) {
        if(a % result==0 && b % result==0) {
            break;
        }
        --result;
    }
    return result;
}

// To be implemented
// TODO 1
Rational::Rational(int num, int den) { //default constructor
    this->denominator=den;
    this->numerator=num;
    if(den == 0) {
        cout << "Denominator cannot be zero.\nReset to 0/1\n";
        // TODO 1.1
        this->denominator = 1;
        this->numerator = 0;
    }
    else if (den < 0) {
        // TODO 1.2
        numerator *= -1;
        denominator *= -1;
    }
    // TODO 1.3
    //At this point the signs of the numerator and denominator values should be correct
    int gcd = get_gcd(numerator, denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
}

// TODO 2
Rational Rational::add(const Rational& b) const {
    int sumNum = this->numerator * b.denominator + b.numerator * this->denominator;
    int sumDen = b.denominator * this->denominator;    
    int gcd = get_gcd(sumNum,sumDen);
    sumNum /= gcd;
    sumDen /= gcd;

    Rational sum(sumNum, sumDen);
    return sum;
}

// TODO 3
Rational Rational::negation() const {
    Rational neg(-this->numerator,this->denominator);
    return neg;
}
