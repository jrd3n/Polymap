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
  void storeConstants(double Constants[], int polynomialDegree);
  short ReturnPolylookup(int lookup);
  double ReturnPolyCalc(double x);

private:
  uint inputToArrayAddress(short input);
  int _resolution = 1;
  short _polyMapArray[];
  int _significantFigures = 2;
  double _E[]; // constants

  int _polynomialDegrees = 0; // number of polynomialDegrees
  short _sizeofPolyMapArray = 0;
  short _MinInput = 0;
  short _MaxInput= 0;
};

#endif