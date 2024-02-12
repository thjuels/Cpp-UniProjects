#ifndef __AIRPORT_H__
#define __AIRPORT_H__

#include "Aircraft.h"
#include "ErrorType.h"

using namespace std;

/**
 * Represent an Airport object
 * Given, do NOT modify
 */
class Airport {
    private:
        const int _capacity;
        int _curSize;
        Aircraft** _parkingAircrafts;
        bool contains(Aircraft* aircraft) const;
        int find(Aircraft* aircraft) const;
        void printErrorMessage(ErrorType type) const;

    public:
        int getCapacity() const;
        int getCurSize() const;
        void print() const;
        bool add(Aircraft* aircraft);
        bool leave(Aircraft* aircraft);
        Airport(int capacity);
        ~Airport();
};

#endif