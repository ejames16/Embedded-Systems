#include "mbed.h"
#include <cmath>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

class DoubleNumber {
private:

protected:
    double _real;

public:
    //Designated constructor
    DoubleNumber(double r) {
        _real = r;
        cout << "This is the constructor of Base" << endl;
    }

    //Convenience constructor
    DoubleNumber() : DoubleNumber(0.0) { }

    //Copy constructor
    DoubleNumber(const DoubleNumber& u) {
        this->setValue(getValue());
    }

    //Magnitude
    double magnitude() {
        return fabs(_real);
    }

    //Three overloaded functions
    void setValue(double u) {
        _real = u;
    }
    void setValue(int u) {
        _real = (double)u;
    }
    void setValue(string strVal) {
        _real = stod(strVal);
    }
    void setValue(DoubleNumber& u) {
        this->setValue(u.getValue());
    }

    double getValue() {
        return _real;
    }

    string asString() {
        return to_string(_real);
    }

    // OVERLOADED OPERATORS
    void operator+=(double u) {
        double sum = this->getValue() + u;
        this->setValue(sum);
    }

    void operator+=(DoubleNumber& u) {
        double sum = this->getValue() + u.getValue();
        this->setValue(sum);
    }

    DoubleNumber operator+(DoubleNumber& u) {
        DoubleNumber result;
        result = *this;
        result += u;
        return result;
    }

    DoubleNumber& operator=(double u) {
        this->setValue(u);
        return *this;
    }
    DoubleNumber& operator=(DoubleNumber& u) {
        this->setValue(u.getValue());
        return *this;
    }
    DoubleNumber& operator=(string s) {
        this->setValue(s);
        return *this;
    }
    bool operator==(DoubleNumber& u)
    {
        // Return a true if u is equal to `this`
        DoubleNumber& number = *this;
        if (number.getValue() == u.getValue())
        {
            return true;
        }
        return false;
        //return (this->_real == u._real) ? true : false;
    }

    operator double() {
        return _real;
    }

};

float f;
int main()
{
    float* pf = &f;

    float& ff = f; 

    float r =1.0;
    pf = &r;

    float y = 3.3;

    ff = y;





    //Constructor Function overloading 
    DoubleNumber n0(1.0);
    DoubleNumber n1;
    DoubleNumber n2;
    DoubleNumber n3;

    //setValue function overloading  
    n1 = 10.0;
    n1 += 1.0;      // Equivalent to n1.operator+=(1.0);
    n2 = "-3.0";
    n3 = n2;

    DoubleNumber sum = (n0 + n1 + n2 + n3);
    cout << sum << endl;

    if (n3 == n2)
    {
        cout << "Equal!" << endl;
    }
    else{
        cout << "Not Equal!" << endl;
  
    }

    while (true) {

    }
}

