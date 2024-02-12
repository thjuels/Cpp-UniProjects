#include <iostream>
#include "set.h"
using namespace std;

int main() {
    Set mySet(5);

    // Insert values into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(10); // This will print "Element already present."

    // Check if the set contains a specific value
    cout << "Set contains 20? " << (mySet.contains(20) ? "Yes" : "No") << endl; 
    // Output: Yes

    // Remove a value from the set
    mySet.remove(20);

    cout << "Set contains 20? " << (mySet.contains(20) ? "Yes" : "No") << endl; 
    // Output: No

    mySet.remove(20); // This will print "Element not found."

    // Display the size of the set
    cout << "Current size: " << mySet.getSize() << endl;

    mySet.insert(20);
    mySet.insert(40);
    mySet.insert(50);
    mySet.insert(60); // This will print "Container is full."

    // Increase the capacity of the set
    mySet.increaseCapacity(5);
    cout << "New capacity: " << mySet.getCapacity() << endl; //10

    // Is Super Set?
    Set myNewSet(5);
    mySet.insert(10);
    cout << "Is Super Set? " << (mySet.isSuperSet(&myNewSet) ? "Yes" : "No") << endl; // Yes
    myNewSet.insert(80);
    cout << "Is Super Set? " << (mySet.isSuperSet(&myNewSet) ? "Yes" : "No") << endl; // No
    
    // Set Union 
    Set* unionSet = mySet.unionSet(&myNewSet);
    cout << "Is Super Set? " << (unionSet->isSuperSet(&myNewSet) ? "Yes" : "No") << endl; // Yes
    delete unionSet;

    return 0;
}