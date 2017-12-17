#include <Arduino.h>
#include <polymap.h>

const PROGMEM float PolyArray[] = {1,2,3,4,5,6,7,8,9}

short Range[] = {0, // lowest value of input information
                 1023 // highest value of input information
} // for analog input the range is from 0 to 1023

short increments = 1; // for analog input the inputs would be 1. If you were reading a digital temp sensor, the range might be 20.0 to 25.6 and the increments would be 0.1

short polynomialConstants[] = {0, // these are the polynomial polynomialconstants, Offset
                               0, // E1
                               0, // E2
                               0, // E3
                               0, // E4
                               0} // E5

polymap Transducer(Range, increments ); // create instance of polymap class name it after the sensor

void setup()
{
    // put your setup code here, to run once:
    Transducer.storeConstants(polynomialConstants[]);
    Transducer.calcAllVals();
}

void loop()
{
    // put your main code here, to run repeatedly:
}