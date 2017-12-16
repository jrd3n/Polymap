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

double polymap::ReturnPolylookup(int lookup)
{
  return _polyMapArray[lookup];
}

void polymap::storeConstants(double offset, double E1, double E2, double E3)
{
}

double polymap::ReturnPolyCalc(double lookup)
{

  return 0;
}