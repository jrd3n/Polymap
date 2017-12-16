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
  polymap(uint8 significantFigures = 2, uint8_t resolution = 0);
  void calcAllVals();
  void storeConstants(double offset, double E1, double E2, double E3);
  short ReturnPolylookup(int lookup);
  short ReturnPolyCalc(double x);

private:
  int _resolution;
  double _polyMapArray[];
  int _resolution;
  int _significantFigures;
};

#endif

/* int Constants[6][3] =  {
  {0, 0, 0} // offset
  {0, 0, 0} // E1
  {0, 0, 0} // E2
  {0, 0, 0} //
  {0, 0, 0}
  {0, 0, 0}
  {0, 0, 0}

} */