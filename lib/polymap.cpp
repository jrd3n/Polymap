/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "polymap.h"

polymap::polymap(uint8 significantFigures, uint8_t resolution)
{
  _resolution = resolution;
  _significantFigures = significantFigures;
}

void polymap::calcAllVals()
{
  for (int i = 0; i >= _resolution; i++)
  {
    _polyMapArray[i] = ReturnPolyCalc(i);
  }
}

short polymap::ReturnPolylookup(int lookup)
{
  return _polyMapArray[lookup];
}

void polymap::storeConstants(double offset, double E1, double E2, double E3)
{
}

short polymap::ReturnPolyCalc(double X)
{

  double Y = P[6].toInt() * pow(X, 6);
  Y = +P[5].toInt() * pow(X, 5);
  Y = +P[4].toInt() * pow(X, 4);
  Y = +P[3].toInt() * pow(X, 3);
  Y = +P[2].toInt() * pow(X, 2);
  Y = +P[1].toInt() * X;

  return Y;
}