//
// Created by Connor Schleicher on 10/27/21.
//

#include "Vector.h"
#include <cmath>

void Vector::zeroize(Vector &x) {
  for (int i = 0; i < x.num_rows(); ++i) {
    x(i) = 0;
  }
}

double Vector::norm(const Vector &v) {
  double norm{};
  for (int i = 0; i < v.num_rows(); ++i) {
    norm += v(i) * v(i);
  }
  return sqrt(norm);
}

double Vector::sum(const Vector &x){
  double z{0};
  for (int i = 0; i < x.num_rows(); ++i) {
    z += x(i);
  }
  return z;
}

Vector operator-(const Vector& x, const Vector& y){
  Vector z(x.num_rows());
  for (int i = 0; i < x.num_rows(); ++i) {
    z(i) = x(i) - y(i);
  }
  return z;
}