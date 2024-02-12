#ifndef __HANGAR_H__
#define __HANGAR_H__

#include "Aircraft.h"

using namespace std;

/**
 * Represent a Hangar object
 * Given, Do NOT change this class
 */
class Hangar {
    private:
        // Define the size of the Hangar
        const int _size;

        // An array of Aircraft objects, representing aircrafts in the Hangar
        Aircraft** _aircrafts;
    public:
        Aircraft* getAircraft(int idx) const;

        int getSize() const;

        Hangar();
        Hangar(Aircraft** aircrafts, int size);
        ~Hangar();
};

#endif