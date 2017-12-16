short polyMap (double X) {

double Y = P[6].toInt() * pow(X, 6);
 Y = + P[5].toInt() * pow(X, 5);
 Y = + P[4].toInt() * pow(X, 4);
 Y = + P[3].toInt() * pow(X, 3);
 Y = + P[2].toInt() * pow(X, 2);
 Y = + P[1].toInt() * X;

  return Y;
}
