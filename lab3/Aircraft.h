#ifndef __AIRCRAFT_H__
#define __AIRCRAFT_H__

#include <string>

using namespace std;

/**
 * Represent an Aircraft object
 */

class Aircraft {
    private:
        string _model;
        string _regNum;
        
    public:
        void print() const;
        string getModel() const;
        string getRegNum() const;
        Aircraft(const string& model, const string& regNum);
};

#endif
