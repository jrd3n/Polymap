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

void polymap::storeConstants(short Constants[])
{
  _ConstElements = sizeof(Constants) / sizeof(short);

  for (int i = 0; i <= _ConstElements; i++)
  {
    _E[i] = Constants[i];
  }
}

short polymap::ReturnPolyCalc(double X)
{

  double Y = 0;

  for (int i = _ConstElements; i = 0; i--)
  {
    Y = +_E[i] * pow(X, i);
  }

  /*
  Y = _E[6] * pow(X, 6);
  Y = +_E[5] * pow(X, 5);
  Y = +_E[4] * pow(X, 4);
  Y = +_E[3] * pow(X, 3);
  Y = +_E[2] * pow(X, 2);
  Y = +_E[1] * pow(X, 1);
  Y = +_E[0] * pow(X, 0);
  */

  return Y;
}

uint inputToArrayAddress(short input)
{
  short y = input - _MinInput;

  return y;
}