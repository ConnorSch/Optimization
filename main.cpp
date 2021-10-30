#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "LeastSquares.cpp"
#include <ctime>
#include <random>


int main() {
  Vector b(3,std::vector<double> {1,2,3});
  Vector x(3);
  Vector::zeroize(x);
  f(x,b);
  std::cout << b << std::endl;
  return 0;
}

