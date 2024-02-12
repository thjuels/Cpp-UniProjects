#include "Aircraft.h"
#include "Hangar.h"
#include "PassengerAircraft.h"
#include "CargoAircraft.h"
#include "Airport.h"
#include "ErrorType.h"
#include <iostream>
#include "test.cpp"
using namespace std;

int main() {
    cout << "Enter the number of test case that you want to run: ";
    int test_case;
    cin >> test_case;
    switch (test_case) {
        case 1:
            test_1();
            break;
        case 2:
            test_2();
            break;
        case 3:
            test_3();
            break;
        case 4:
            test_4();
            break;
        case 5:
            test_5();
            break;
        case 6:
            test_6();
            break;
        case 7:
            test_7();
            break;
        case 8:
            test_8();
            break;
        default:
            cout << "Invalid test case" << endl;
            break;
    }
    return 0;
}

