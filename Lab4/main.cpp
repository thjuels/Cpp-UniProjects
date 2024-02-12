#include <iostream>
#include "set.h"
using namespace std;

int main() {
    Set* mySet;

    // Test 1
    mySet = new Set(5);
    mySet->insert(10);
    mySet->insert(20);
    mySet->insert(10); // Element already present.
    cout << "Set contains 20? " << (mySet->contains(20) ? "Yes" : "No") << endl; // Yes
    delete mySet;
    cout << endl;

    // Test 2
    mySet = new Set(5);
    mySet->insert(10);
    mySet->insert(20);
    mySet->insert(10); // Element already present.
    mySet->remove(30); // Element not found.
    cout << "Set contains 20? " << (mySet->contains(20) ? "Yes" : "No") << endl; // Yes
    cout << "Current size: " << mySet->getSize() << endl; // Current size: 2
    mySet->remove(10);
    cout << "Current size: " << mySet->getSize() << endl; // Current size:  1
    delete mySet;
    cout << endl;

    // Test 3
    mySet = new Set(2);
    mySet->insert(10);
    mySet->insert(30);
    mySet->insert(20); // Container is full.
    mySet->remove(20); // Element not found.
    cout << "Current size: " << mySet->getSize() << endl; // Current size: 2
    mySet->increaseCapacity(1); // Set Capacity Increased by: 1
    mySet->insert(20);
    cout << "Set contains 20? " << (mySet->contains(20) ? "Yes" : "No") << endl; // Yes
    cout << "Current size: " << mySet->getSize() << endl; // Current size: 3
    delete mySet;
    cout << endl;

    // Test 4
    mySet = new Set(2);
    Container* myContainer = mySet;
    mySet->insert(10);
    mySet->insert(30);
    mySet->insert(20); // Container is full.
    mySet->remove(20); // Element not found.
    cout << "Current size: " << myContainer->getCapacity() << endl; // Current Capacity:  2
    mySet->increaseCapacity(1);
    cout << "Current size: " << myContainer->getCapacity() << endl; // Current Capacity:  3
    mySet->insert(20);
    cout << "Set contains 20? " << (mySet->contains(20) ? "Yes" : "No") << endl; // Yes
    delete mySet;
    cout << endl;

    // Test 5
    mySet = new Set(3);
    mySet->insert(10);
    mySet->insert(20);
    mySet->insert(30); 
    Set* myNewSet = new Set(3);
    myNewSet->insert(10);
    myNewSet->insert(20);
    cout << "Is Super Set? " << (mySet->isSuperSet(myNewSet) ? "Yes" : "No") << endl; // Yes
    myNewSet->insert(40);
    cout << "Is Super Set? " << (mySet->isSuperSet(myNewSet) ? "Yes" : "No") << endl; // No
    Set* unionSet = mySet->unionSet(myNewSet);
    cout << "Is Super Set? " << (unionSet->isSuperSet(myNewSet) ? "Yes" : "No") << endl; // Yes
    delete mySet;
    delete unionSet;
    delete myNewSet;
    cout << endl;


    return 0;
}
