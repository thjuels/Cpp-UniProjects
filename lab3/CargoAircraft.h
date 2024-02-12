#ifndef __CARGOAIRCRAFT_H__
#define __CARGOAIRCRAFT_H__

#include "Aircraft.h"

using namespace std;


/**
 * Represent a CargoAircraft object
 */

class CargoAircraft : public Aircraft {
    private:
        float _loadedWeight;

    public:
        float getLoadedWeight() const;
        void print() const;
        CargoAircraft(string model, string regNum, float loadedWeight);
};

#endif
