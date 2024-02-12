#include "Airport.h"
#include <iostream>

using namespace std;

// TODO 4.1: Implement the Airport constructor here, remember to initialize all the member variables
Airport::Airport(int capacity):_capacity(capacity),_curSize(0){
    _parkingAircrafts = new Aircraft*[capacity];
    for (int i =0; i< capacity; i++){
        _parkingAircrafts[i] = nullptr;
    }
}

// TODO 4.1: Implement the Airport destructor here, remember to free all the memory allocated
Airport::~Airport() {
    delete [] _parkingAircrafts;
}

// TODO 4.2: Implement add function here - Arriving aircraft
bool Airport::add(Aircraft* aircraft) {
    if (aircraft){
        if (this->contains(aircraft)){
            printErrorMessage(ErrorType::AIRCRAFT_EXISTS_IN_AIRPORT);
            return false;
        }
        else if (this->getCurSize()==this->_capacity){
            printErrorMessage(ErrorType::AIRPORT_IS_FULL);
            return false;
        }
        else {
            //lazy af way faster way -> have already checked if its full, so array pos of _curSize would be where new one place anyway
            // if(!_parkingAircrafts[_curSize]){//if nullptr
            //     _parkingAircrafts[_curSize++] = aircraft;
            //     return true;
            // }
            //not lazy way - if above doesn't work
            for (int j = 0; j < _capacity; j++){
                if (_parkingAircrafts[j] == nullptr){
                    _parkingAircrafts[j] = aircraft;
                    _curSize++;
                    return true;
                }
            }
        }
    }
    else{
        printErrorMessage(ErrorType::NULL_PTR);
        return false;
    }
    return false;
}

// TODO 4.3: Implement leave function here
bool Airport::leave(Aircraft* aircraft) {
    // Delete the following line and write your own code
    if (aircraft){
        if (this->contains(aircraft)){
            //continue to delete
            int index = this->find(aircraft);
            // delete _parkingAircrafts[index]; not neccessary as the 'Aircraft*' pointer can still be kept
            _parkingAircrafts[index] = nullptr;
            _curSize--;
            return true;
        }
        else {
            printErrorMessage(ErrorType::AIRCRAFT_NOT_FOUND_IN_AIRPORT);
            return false;
        }
    }
    else{
        printErrorMessage(ErrorType::NULL_PTR);
        return false;
    }
    return false;
}

// Given, do NOT modify
void Airport::print() const {
    cout << "This beautiful airport has capacity of " << this->_capacity << " and currently has " << this->_curSize << " aircrafts" << endl;
}

/**
 * Given, do NOT modify
 * The printErrorMessage function prints the error message based on the error type
 * @param type The error type
 */
void Airport::printErrorMessage(ErrorType type) const {
    switch (type) {
        case ErrorType::NULL_PTR:
            cout << "Null pointer detected!" << endl;
            break;
        case ErrorType::AIRCRAFT_EXISTS_IN_AIRPORT:
            cout << "Aircraft already exists in airport!" << endl;
            break;
        case ErrorType::AIRCRAFT_NOT_FOUND_IN_AIRPORT:
            cout << "Aircraft not found in airport!" << endl;
            break;
        case ErrorType::AIRPORT_IS_FULL:
            cout << "Airport is full!" << endl;
            break;
    }
}

int Airport::getCapacity() const {
    return this->_capacity;
}

int Airport::getCurSize() const {
    return this->_curSize;
}

/**
 * Given, do NOT modify
 * The contains function checks if the aircraft is already in the airport
 * @param aircraft The aircraft to be checked
 * @return true if the aircraft is already in the airport, false otherwise
 */
bool Airport::contains(Aircraft* aircraft) const {
    return find(aircraft) != -1;
}

/**
 * Given, do NOT modify
 * The find function finds the index of the aircraft in the airport
 * @param aircraft The aircraft to be found
 * @return the index of the aircraft in the airport, -1 if not found
 */
int Airport::find(Aircraft* aircraft) const {
    if (aircraft == nullptr) {
        return -1;
    }
    for (int i = 0; i < this->_capacity; i++) {
        if (this->_parkingAircrafts[i] == aircraft) {
            return i;
        }
    }
    return -1;
}