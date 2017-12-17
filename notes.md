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
| 10 | 1 |
| 9   | 2 |
|8  |3 |
| 3 | 6 |

1. set to 3 degrees

the output is this;

```

double f(double x) {
   return  4.1428571428767373e+000 * pow(x,0)
        +  1.3047619047510288e+000 * pow(x,1)
        + -2.5714285714116780e-001 * pow(x,2)
        +  9.5238095237296320e-003 * pow(x,3);
}

```
these are our polynomal constants.

## Notes

short polyMap (double X) {

double Y = P[6].toInt() * pow(X, 6);
 Y = + P[5].toInt() * pow(X, 5);
 Y = + P[4].toInt() * pow(X, 4);
 Y = + P[3].toInt() * pow(X, 3);
 Y = + P[2].toInt() * pow(X, 2);
 Y = + P[1].toInt() * X;

  return Y;
}
