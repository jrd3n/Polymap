#include <Arduino.h>
#include <polymap.h>

const PROGMEM double PolyArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

double polynomialConstants[] = { // these are the polynomial constants,
    1.0000000000000000e+001,    // Offset
    -1.9952380952380973e+000,    // first degree
    1.0952380952380976e-001};   // second degree
    
short Range[] = {
    0,   // lowest value of input information
    1023 // highest value of input information
};       // for analog input the range is from 0 to 1023

short increments = 1; // for analog input the inputs would be 1. If you were reading a digital temp sensor, the range might be 20.0 to 25.6 and the increments would be 0.1

polymap Transducer(Range, increments); // create instance of polymap class name it after the sensor

void setup()
{
    Serial.begin(115200);
    Serial.println("connected");
    // put your setup code here, to run once:
    Transducer.storeConstants(polynomialConstants, 2);
    // Transducer.calcAllVals();

        for (int i = 0; i < 10; i++)
    {
        Serial.print(i);
        Serial.print(" = ");

        Serial.println(Transducer.ReturnPolyCalc(i));
    }
}

void loop()
{

    // put your main code here, to run repeatedly:
}