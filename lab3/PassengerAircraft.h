#ifndef __PASSENGERAIRCRAFT_H__
#define __PASSENGERAIRCRAFT_H__

#include "Aircraft.h"

using namespace std;

/**
 * Represent a PassengerAircraft object
 */

class PassengerAircraft : public Aircraft {
    private:
        int _numPassenger;

    public:
        int getNumPassenger() const;
        void print() const;
        PassengerAircraft(string model, string regNum, int numPassenger);
};

#endif
