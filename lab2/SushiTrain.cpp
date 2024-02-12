#include <iostream>
#include "SushiTrain.h"
using namespace std;

// TODO #5 ~ TODO #10: add your code here
// Helper for TODO #8: cout << "Insufficient capacity" << endl;
// Helper for TODO #9: cout << "No sushi can be removed" << endl;
SushiTrain::SushiTrain(int capacity) :_capacity(capacity), _numSushi(0) {
    _sushi = new Sushi[capacity];
}

SushiTrain::SushiTrain(const Sushi sushi[], int numSushi)
:_capacity(numSushi), _numSushi(numSushi){
    _sushi = new Sushi[numSushi];
    for(int i = 0; i < numSushi ; i++ ){
        _sushi[i].clone(sushi[i]); //essentially same as consructor below, in terms of execution,
        //however bottom one takes SushiTrain object as input.
    }
}

SushiTrain:: SushiTrain(const SushiTrain& st)
:_capacity(st._capacity), _numSushi(st._numSushi){
    _sushi = new Sushi[st._capacity];
    for ( int i = 0; i < st._numSushi; i++){ //if _numSushi < _capacity, it will only copy all it needs, if they are same, great
        // _sushi[i] = st._sushi[i];//not deep copy
        _sushi[i].clone(st._sushi[i]);
    }
}

void SushiTrain::addSushi(const Sushi& s){
    if (_capacity >= _numSushi){
        cout << "Insufficient capacity" << endl;
    } 
    else {
        // this->_sushi[_numSushi].clone(s);
        // this->_numSushi++;
        // instead of above 2 lines
        _sushi[_numSushi++].clone(s);
    }
}

void SushiTrain::removeLastSushi(){
    if (_numSushi == 0){
        cout << "No Sushi can be removed!" << endl;
    }
    else {
        --_numSushi; //no need to actually delete, as the when the deconstructor is called, it deletes the memory, which calls the ~Sushi to properly dallocate dynamic memory
    } //If a sushi is deleted, then a new one added in that position
}

int SushiTrain::totalPrice() const {
    int sum = 0;
    for (int i = 0; i< _numSushi; i++){
        sum += _sushi[i].getPrice();
    }
    return sum;
}


// End of TODO #5 ~ TODO #10
// ***************************************************
// Do not modify the codes below

SushiTrain::~SushiTrain(){
    delete [] _sushi;
}

void SushiTrain::print() const{
    if(_numSushi == 0)
        cout << "Capacity = " << _capacity << ", there is no sushi on the Sushi Train." << endl;
    else{
        for(int i = 0; i < _numSushi; ++i){
            _sushi[i].print();
            cout << " ";
        }
        cout << endl;
    }
    cout << "Capacity = " << _capacity <<", total price for " << _numSushi << " sushi is $" << totalPrice() << endl;
    return;
}
