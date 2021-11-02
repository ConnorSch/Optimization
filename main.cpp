#include <iostream>
#include "Vector.h"
#include "Algorithms.h"


static Vector b(3,std::vector<double> {1,2,3});

int main() {
  Vector x0(3);
  x0.zeroize();
  Algorithms alg{Algorithms::GD};
  Vector x(alg.GradientDescent(x0,b));
  std::cout << x << "\n";
  std::cout << alg.get_obj_his() << "\n";
  std::cout << alg.get_err_his() << "\n";
  return 0;
}

