#include "Hangar.h"

using namespace std;

/**
 * Given, do NOT modify
 * Get the Aircraft pointer at the specified index
 * @param index The index of the Aircraft pointer
 * @return The Aircraft pointer at the specified index, or nullptr if the index is out of bound
 */
Aircraft* Hangar::getAircraft(int idx) const{
    if (idx < 0 || idx >= this->_size) {
        return nullptr;
    }

    return this->_aircrafts[idx];
}

/**
 * Get the size of the Hangar
 * @return The size of the Hangar
 */
int Hangar::getSize() const{
    return this->_size;
}

Hangar::Hangar() : _size(0), _aircrafts(nullptr) {}

Hangar::Hangar(Aircraft** aircrafts, int size): _size(size), _aircrafts(aircrafts) {}

// TODO 3: Implement the destructor
Hangar::~Hangar() {
    if (_aircrafts){
        for (int k=0;k<_size;k++){
            delete _aircrafts[k];
            _aircrafts[k] = nullptr;
        }
        delete [] _aircrafts;
    }
}