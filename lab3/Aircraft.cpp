#include "Aircraft.h"
#include <iostream>

using namespace std;


Aircraft::Aircraft(const string& model, const string& regNum) {
    this->_model = model;
    this->_regNum = regNum;
}

void Aircraft::print() const {
    cout << "Aircraft Model: " << this->getModel() << " with registration number " << this->getRegNum() << endl;
}

string Aircraft::getModel() const {
    return this->_model;
}

string Aircraft::getRegNum() const {
    return this->_regNum;
}
