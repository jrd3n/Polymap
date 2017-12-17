/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef polymap_h
#define polymap_h

#include "Arduino.h"

class polymap
{
public:
  polymap(short Range[], short resolution);
  void calcAllVals();
  void storeConstants(float Constants[], int polynomialDegree);
  short ReturnPolylookup(int lookup);
  short ReturnPolyCalc(double x);

private:
  uint inputToArrayAddress(short input);

  int _resolution;
  short _polyMapArray[];
  int _significantFigures;
  short _E[]; // constants

  int _polynomialDegrees; // number of polynomialDegrees
  short _sizeofPolyMapArray;

  short _MinInput;
  short _MaxInput;
};

#endif