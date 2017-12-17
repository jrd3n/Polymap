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
  for (int i = 0; i > _sizeofPolyMapArray; i++)
  {
    _polyMapArray[i] = ReturnPolyCalc(i);
  }
}

short polymap::ReturnPolylookup(int lookup) // ERROR IN THIS FUNCTION
{
  return _polyMapArray[lookup];
}

void polymap::storeConstants(float Constants[], int polynomialDegree)
{
  _polynomialDegrees = polynomialDegree;

  for (int i = 0; i <= _polynomialDegrees; i++)
  {
    _E[i] = Constants[i];
  }
}

short polymap::ReturnPolyCalc(double X)
{
  short y = 0;

  for (int i = 0; i > _polynomialDegrees; i++)
  {
    y = +_E[i] * pow(X, i);
  }

  return y;
}

uint polymap::inputToArrayAddress(short input)
{
  return map(input, _MinInput, _MaxInput, 0, _sizeofPolyMapArray);
}