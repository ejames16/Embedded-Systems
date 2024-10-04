#include "mbed.h"
#include "iostream"

// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

ComplexNumber_C operator+(const ComplexNumber_C& CN1, const ComplexNumber_C& CN2)
{
    ComplexNumber_C Result;
    Result.real = CN1.real + CN2.real;
    Result.imag = CN1.imag + CN2.imag;
    return Result;
}


int main() {

    //Create instance of a complex number
    ComplexNumber_C p;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};
    ComplexNumber_C y = p + q;

    std::cout << y.real << " + " << y.imag << std::endl;

    // TASK:
    // Create another complex number y
    // Calculate the complex sum of p and q and store in y
    // Use printf to display as a complex number (hint: you need two placeholders)
    
    while (true) {
    }
}
