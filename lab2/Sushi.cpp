#include <iostream>
#include <cstring>
#include "Sushi.h"
using namespace std;

// TODO #1 ~ TODO #4: add your code here
Sushi::Sushi():_name(nullptr),_price(0){
    // _name=nullptr; //OR this->_name=nullptr
    // _price=0;   //OR this->_price=price
}

Sushi::Sushi(const char* name, int price):_name(nullptr),_price(price){
    if (name){
        _name = new char[strlen(name) + 1];//+1 neccesary due to null char at end 
        strcpy(_name,name);
    }
}

Sushi::Sushi(const Sushi& s):Sushi(s._name,s._price){ //smart usage of the other constructor, allows deep copy
    // this->_name = new char[strlen(s._name)+1]; //create new memory location, strlen doesn' include null
    // strcpy(this->_name, s._name);
    // this->_price = s._price;
}

void Sushi::clone(const Sushi& s){
    if (this != &s){

        delete [] _name; //delete the current name in memeroy as it is likely different size
        _price = s._price;

        if (s._name)
        {
            _name = new char[strlen(s._name)+1]; //create new memory location, strlen doesn' include null
            strcpy(_name, s._name);
        }
        else {
            _name = nullptr;
        }
    }
    else
        cout << "NO self cloning" << endl;
}

// End of TODO #1 ~ TODO #4
// ***************************************************
// Do not modify the codes below

Sushi::~Sushi(){
    delete [] _name;
}

int Sushi::getPrice() const{
    return _price;
}

void Sushi::print() const{
    if(!_name)
        cout<< "No sushi: $" << _price;
    else
        cout << _name << " Sushi: $" << _price;
}
