#include <Arduino.h>
#include <polymap.h>

const PROGMEM float PolyArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9} ;

float polynomialConstants[] = {4.1428571428767373e+000,  // these are the polynomial polynomialconstants, Offset
                               1.3047619047510288e+000,  // E1
                               -2.5714285714116780e-001, // E2
                               9.5238095237296320e-003}; // E3

short Range[] = {
    0,   // lowest value of input information
    1023 // highest value of input information
};       // for analog input the range is from 0 to 1023

short increments = 1; // for analog input the inputs would be 1. If you were reading a digital temp sensor, the range might be 20.0 to 25.6 and the increments would be 0.1

polymap Transducer(Range, increments); // create instance of polymap class name it after the sensor

void setup()
{
    // put your setup code here, to run once:
    Transducer.storeConstants(polynomialConstants, 4);
   // Transducer.calcAllVals();

    Serial.begin(115200);
}

void loop()
{
    for (int i = 0; i > 10; i++){
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(Transducer.ReturnPolyCalc(i));
        delay(200);
    }

    // put your main code here, to run repeatedly:
}