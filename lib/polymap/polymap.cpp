/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "polymap.h"

polymap::polymap(short Range[], short resolution)
{
  _resolution = resolution;
  _MinInput = Range[0];
  _MaxInput = Range[1];

  _sizeofPolyMapArray = (_MaxInput - _MinInput) / _resolution;
}

void polymap::calcAllVals() // ERROR IN THIS FUNCTION
{
  for (int i = 0; i < _sizeofPolyMapArray; i++)
  {
    _polyMapArray[i] = ReturnPolyCalc(i);
  }
}

short polymap::ReturnPolylookup(int lookup) // ERROR IN THIS FUNCTION
{
  return _polyMapArray[lookup];
}

void polymap::storeConstants(double Constants[], int polynomialDegree)
{

  for (int i = 0; i < polynomialDegree + 1; i++)
  {

    Serial.print("_E[");
    Serial.print(i);
    Serial.print("] = ");
    _E[i] = Constants[i];
    Serial.println(_E[i]);
  }

  _polynomialDegrees = polynomialDegree;

  /*

  Serial.print("_polynomialDegrees = ");
  Serial.println(_polynomialDegrees);

  Serial.print("polynomialDegree = ");
  Serial.println(polynomialDegree);

  */
}

double polymap::ReturnPolyCalc(double X)
{
  double y = 0;

  int yShort = 0;

  for (int i = 0; i < _polynomialDegrees + 1; i++)
  {
    y += (_E[i] * pow(X, i));
  }

  yShort = y * pow(10, _significantFigures);

  return yShort / pow(10, _significantFigures);
}

uint polymap::inputToArrayAddress(short input)
{
  return map(input, _MinInput, _MaxInput, 0, _sizeofPolyMapArray);
}