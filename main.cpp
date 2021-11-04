#include <iostream>
#include "Vector.h"
#include "Algorithms.h"


static Vector b(3,std::vector<double> {1,2,3});

int main() {
  Vector x0(3);
  x0.zeroize();
  Algorithms alg{Algorithms::GD};
  Algorithms alg2{Algorithms::NR};
  Functions func{Functions::LeastSquares};
  Vector x(alg.GradientDescent(x0,b,func));
  Vector x2(alg2.NewtonRaphson(x0,b,func));

  std::cout << "Gradient Descent Method \n";
  std::cout << x << "\n";
  std::cout << alg.get_obj_his() << "\n";
  std::cout << alg.get_err_his() << "\n";
  std::cout << "Newton Raphson Method \n";
  std::cout << x2 << "\n";
  std::cout << alg2.get_obj_his() << "\n";
  std::cout << alg2.get_err_his() << "\n";
  return 0;
}