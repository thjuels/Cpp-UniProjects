#include <iostream>
#include "Aircraft.h"
#include "Hangar.h"
#include "PassengerAircraft.h"
#include "CargoAircraft.h"
#include "Airport.h"
#include "ErrorType.h"

using namespace std;

void add_wrap_message(bool result) {
    if (result) {
        cout << "Aircraft was successfully added" << endl;
    } else {
        cout << "Aircraft was not added" << endl;
    }
}

void leave_wrap_message(bool result) {
    if (result) {
        cout << "Aircraft was successfully left" << endl;
    } else {
        cout << "Aircraft was not left" << endl;
    }
}

void print_on_operation(Aircraft* aircraft) {
    if (aircraft != nullptr) {
        cout << "Performing operation on aircraft: " << aircraft->getModel() << " with registration number " << aircraft->getRegNum() << endl;
    } else {
        cout << "Performing operation on: Aircraft was not found" << endl;
    }
}

void test_add_wrapper(Airport* airport, Aircraft* aircraft) {
    print_on_operation(aircraft);
    bool result = airport->add(aircraft);
    add_wrap_message(result);
}

void test_leave_wrapper(Airport* airport, Aircraft* aircraft) {
    print_on_operation(aircraft);
    bool result = airport->leave(aircraft);
    leave_wrap_message(result);
}


// Test PassengerAircraft Implementation
void test_1() {
    PassengerAircraft* aircraft = new PassengerAircraft("Boeing 787", "XYZ456", 100);
    aircraft->print();
    delete aircraft;
}

// Test CargoAircraft Implementation
void test_2() {
    CargoAircraft* aircraft2 = new CargoAircraft("Airbus 340", "KK414", 57.8);
    aircraft2->print();
    delete aircraft2;
}

// Test Hangar Implementation
void test_3() {
    Aircraft** aircrafts = new Aircraft*[2];
    Aircraft* aircraft = new Aircraft("Boeing 747", "ABC123");
    aircraft->print();
    PassengerAircraft* aircraft_2 = new PassengerAircraft("Boeing 787", "COM123",123);
    aircraft_2->print();
    aircrafts[0] = aircraft;
    aircrafts[1] = aircraft_2;
    cout << "Create Hangar with aircrafts (size 2)" << endl;
    Hangar* hangar = new Hangar(aircrafts, 2);
    cout << "Delete the Hangar" << endl;
    delete hangar;
}

// Test Hangar Implementation
void test_4() {
    cout << "Create Hangar with default constructor" << endl;
    Hangar* hangar_2 = new Hangar();
    cout << "Delete the Hangar" << endl;
    delete hangar_2;
}


// Test Airport Implementation (add function)
void test_5() {
    Airport airport = Airport(1);
    Aircraft* aircraft = new Aircraft("Boeing 747", "ABC123");
    aircraft->print();
    Aircraft* aircraft_2 = new Aircraft("Boeing 787", "COM123");
    aircraft_2->print();
    Aircraft* aircraft_3 = new Aircraft("DC-10", "123456");
    aircraft_3->print();

    test_add_wrapper(&airport, aircraft);

    test_add_wrapper(&airport, aircraft);

    test_add_wrapper(&airport, aircraft_2);

    test_add_wrapper(&airport, aircraft_3);

    delete aircraft;
    delete aircraft_2;
    delete aircraft_3;
}

// Test Airport Implementation (leave function)
void test_6() {
    Airport airport = Airport(1);
    Aircraft* aircraft = new Aircraft("Boeing 747", "ABC123");
    aircraft->print();
    PassengerAircraft* aircraft_2 = new PassengerAircraft("Boeing 787", "COM123",123);
    aircraft_2->print();
    CargoAircraft* aircraft_3 = new CargoAircraft("DC-10", "123456", 5.6);
    aircraft_3->print();

    test_add_wrapper(&airport, aircraft);

    test_add_wrapper(&airport, aircraft_2);

    test_add_wrapper(&airport, aircraft_3);

    test_leave_wrapper(&airport, aircraft);

    test_leave_wrapper(&airport, aircraft);

    test_leave_wrapper(&airport, aircraft_2);

    test_leave_wrapper(&airport, aircraft_3);

    delete aircraft;
    delete aircraft_2;
    delete aircraft_3;
}

Hangar* integrated_test_construction() {
    int size = 5;
    Aircraft** aircrafts = new Aircraft*[size];

    Aircraft* aircraft_1 = new Aircraft("Boeing 747", "ABC123");
    aircraft_1->print();

    PassengerAircraft* aircraft_2 = new PassengerAircraft("Boeing 787", "DEF456",300);
    aircraft_2->print();

    PassengerAircraft* aircraft_3 = new PassengerAircraft("Boeing 737", "GHI789",150);
    aircraft_3->print();

    CargoAircraft* aircraft_4 = new CargoAircraft("Airbus 340", "JKL012",26.8);
    aircraft_4->print();

    CargoAircraft* aircraft_5 = new CargoAircraft("McDonnell Douglas DC-10", "MNO345",10.8);
    aircraft_5->print();

    aircrafts[0] = aircraft_1;
    aircrafts[1] = aircraft_2;
    aircrafts[2] = aircraft_3;
    aircrafts[3] = aircraft_4;
    aircrafts[4] = aircraft_5;

    Hangar* hangar = new Hangar(aircrafts, size);
    return hangar;
}

// Intergrated Test 1
void test_7() {
    Hangar* hangar = integrated_test_construction();
    Airport airport = Airport(2);

    airport.print();
    test_add_wrapper(&airport, hangar->getAircraft(0));

    airport.print();
    test_add_wrapper(&airport, hangar->getAircraft(1));

    airport.print();
    test_add_wrapper(&airport, hangar->getAircraft(2));

    airport.print();
    test_leave_wrapper(&airport, hangar->getAircraft(0));

    airport.print();
    test_add_wrapper(&airport, hangar->getAircraft(3));

    airport.print();
    test_leave_wrapper(&airport, hangar->getAircraft(1));

    airport.print();
    test_add_wrapper(&airport, hangar->getAircraft(4));

    airport.print();
    test_leave_wrapper(&airport, hangar->getAircraft(2));

    airport.print();
    test_leave_wrapper(&airport, hangar->getAircraft(5));

    airport.print();
    test_add_wrapper(&airport, hangar->getAircraft(5));

    airport.print();
    test_leave_wrapper(&airport, hangar->getAircraft(3));

    airport.print();

    delete hangar;

}

// Integrated Test 2
void test_8() {
    Hangar* hangar = integrated_test_construction();
    Airport airport = Airport(3);

    airport.print();

    test_add_wrapper(&airport, hangar->getAircraft(5));
    airport.print();

    test_add_wrapper(&airport, hangar->getAircraft(4));
    airport.print();

    test_add_wrapper(&airport, hangar->getAircraft(4));
    airport.print();

    test_leave_wrapper(&airport, hangar->getAircraft(3));
    airport.print();

    test_add_wrapper(&airport, hangar->getAircraft(3));
    airport.print();

    test_add_wrapper(&airport, hangar->getAircraft(2));
    airport.print();

    test_add_wrapper(&airport, hangar->getAircraft(1));
    airport.print();

    test_leave_wrapper(&airport, hangar->getAircraft(3));
    airport.print();

    test_leave_wrapper(&airport, hangar->getAircraft(5));
    airport.print();

    test_leave_wrapper(&airport, hangar->getAircraft(1));
    airport.print();

    delete hangar;

}
