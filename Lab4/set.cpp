#include "set.h"
#include <iostream>

Set::Set(int cap) : Container(cap) {}

void Set::insert(int element) {
    if (contains(element)) {
        std::cout << "Element already present." << std::endl;
        return;
    }
    Container::insert(element);
}

bool Set::isSuperSet(const Set* anotherSet) const {
    for (int i = 0; i < anotherSet->size; i++) {
        if (!contains(anotherSet->storage[i])) {
            return false;  // The current set doesn't contain an element from the anotherSet, so it's not a superset.
        }
    }
    return true;
}

Set* Set::unionSet(const Set *anotherSet) const {
    Set* ret = new Set(getSize()+anotherSet->getSize());
    for (int i = 0; i < anotherSet->size; i++) {
        if (!ret->contains(anotherSet->storage[i])) {
            ret->insert(anotherSet->storage[i]);
        }
    }    
    for (int i = 0; i < size; i++) {
        if (!ret->contains(storage[i])) {
            ret->insert(storage[i]);
        }
    }
    return ret;
}