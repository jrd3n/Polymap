# design brief

## Targets

1. generate polynomial results from the constants and X
2. generate an array that can be stored in PROGMEM
3. use the array to lookup value rather than calculate.

## Useful websites

<https://arachnoid.com/polysolve/>

### data used;

| measured values | sensor value |
| --- | --- |
| 0 | 10 |
| 3 | 5 |
| 10 | 1 |

1. set to 2 degrees

the output is this;

```
double f(double x) {
   return  1.0000000000000000e+001 * Math.pow(x,0)
        + -1.9952380952380973e+000 * Math.pow(x,1)
        +  1.0952380952380976e-001 * Math.pow(x,2);
}

```
these are our polynomal constants.

## Notes

double polyMap (double X) {

double Y = P[6].toInt() * pow(X, 6);
 Y = + P[5].toInt() * pow(X, 5);
 Y = + P[4].toInt() * pow(X, 4);
 Y = + P[3].toInt() * pow(X, 3);
 Y = + P[2].toInt() * pow(X, 2);
 Y = + P[1].toInt() * X;

  return Y;
}

### Or 

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

# headings for library

1. PolyMap (initialize)
1. Begin
1. Read.
1. Zero
1. End.





