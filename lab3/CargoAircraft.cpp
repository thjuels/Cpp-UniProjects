#include "CargoAircraft.h"
#include <iostream>
#include <iomanip>

using namespace std;

float CargoAircraft::getLoadedWeight() const {
    return this->_loadedWeight;
}

/**
 * Print the CargoAircraft object, do NOT change this function
 */
void CargoAircraft::print() const {
    cout << "Cargo Aircraft Model: " << this->getModel() << " with registration number " << this->getRegNum() << " and loaded " << setprecision(3) << this->getLoadedWeight() << " tons of cargo." << endl;
}

// TODO 2.2: Implement the CargoAircraft class here
CargoAircraft::CargoAircraft(string model, string regNum, float loadedWeight):Aircraft(model,regNum){
    _loadedWeight = loadedWeight;
}