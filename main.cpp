#include <iostream>
#include "Vector.h"
#include "Algorithms.h"
#include "Matrix.h"
#include "LinAlg.h"

static Vector b(3,std::vector<double> {1,2,3});

void SetMatrix(Matrix& A){
//  size_t counter{0};
//  for (int i = 0; i < A.num_rows(); ++i) {
//    for (int j = 0; j < A.num_cols(); ++j) {
//      A(i,j) = ++counter;
//    }
//  }
  A(0,0) = 1;
  A(1,1) = 1;
  A(2,0) = 1;
}

int main() {
//  Vector x0(3);
//  x0.zeroize();
//  Algorithms alg{Algorithms::GD};
//  Algorithms alg2{Algorithms::NR};
//  Functions func{Functions::LeastSquares};
//  Vector x(alg.GradientDescent(x0,b,func));
//  Vector x2(alg2.NewtonRaphson(x0,b,func));
//
//  std::cout << "Gradient Descent Method \n";
//  std::cout << x << "\n";
//  std::cout << alg.get_obj_his() << "\n";
//  std::cout << alg.get_err_his() << "\n";
//  std::cout << "Newton Raphson Method \n";
//  std::cout << x2 << "\n";
//  std::cout << alg2.get_obj_his() << "\n";
//  std::cout << alg2.get_err_his() << "\n";
  Matrix A(3,2);
  SetMatrix(A);
  std::cout << A << "\n";
  Matrix Q(QR(A));
  std::cout << Q << "\n";
  return 0;
}