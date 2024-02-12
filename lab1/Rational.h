#ifndef RATIONAL
#define RATIONAL

#include<iostream>
using namespace std;


//any rational number can be represented as numerator/denominator
//Rule 1. always make the denominator positive. -3/-5 should be stored as 3/5
//Rule 2. the get_gcd function returns the greast common denominator of a and b. and get_gcd(a,b)=get_gcd(-a,b)=get_gce(a,-b)=get_gcd(-a,-b);
//Rule 3. you may assume no overflow
class Rational {
    private:
        int numerator, denominator;
    public:
        void print() const {  //for output
            cout << numerator;
            if ((denominator != 1) && (numerator != 0)) {
                cout << "/" << denominator << endl;
            } else 
            cout << endl;
        }

        Rational(int num=0, int den=1);
        ~Rational() {}
        
        Rational add(const Rational& b) const;  //perform c=a+b
        Rational negation() const;  //perform c=-a
};

#endif
