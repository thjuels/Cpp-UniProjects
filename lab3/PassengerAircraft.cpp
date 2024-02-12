#include "PassengerAircraft.h"
#include <iostream>

using namespace std;


int PassengerAircraft::getNumPassenger() const{
    return this->_numPassenger;
}

/**
 * Print the PassengerAircraft object, do NOT change this function
 */
void PassengerAircraft::print() const {
    cout << "Passenger Aircraft Model: " << this->getModel() << " with registration number " << this->getRegNum() << " and " << this->getNumPassenger() << " passengers" << endl;
}

// TODO 2.1: Implement the PassengerAircraft class here

PassengerAircraft::PassengerAircraft(string model, string regNum, int numPassenger)
:Aircraft(model, regNum),_numPassenger(numPassenger){}
