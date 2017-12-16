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
  polymap(short Range[], short resolution );
  void calcAllVals();
  void polymap::storeConstants(short Constants[]);
  short ReturnPolylookup(int lookup);
  short ReturnPolyCalc(double x);
  
  
private:
  uint inputToArrayAddress(short input);
  int _resolution;
  short _polyMapArray[];
  int _resolution;
  int _significantFigures;
  short _E[]; // constants
  short _MinInput;
  short _MaxInput;
  int _ConstElements; // number of constant elements
  uint _sizeofPolyMapArray;
  
};

#endif