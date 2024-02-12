#include "Rational.h"
#include<iostream>
using namespace std;

int main() {
    cout << "Rational number 1:\nInitialized by default constructor\n";
    Rational r1(1,3);
    r1.print();

    cout << "Rational number 2:\nInitialized by default constructor\n";
    Rational r2(7, 0);
    r2.print();

    cout << "Rational number 3:\nInitialized by default constructor\n";
    Rational r3(2, -5);
    r3.print();

    cout << "Rational number 4:\nInitialized by adding Rational number 1 and Rational number 3\n";
    Rational r4=r1.add(r3);
    r4.print();

    cout << "Rational number 5:\nInitialized by adding Rational number 3 and Rational number 4\n";
    Rational r5=r3.add(r4);
    r5.print();

    cout << "Rational number 6:\nNegation of Rational Number 3\n";
    r3.negation().print();
}
