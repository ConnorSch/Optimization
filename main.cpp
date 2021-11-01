#include <iostream>
#include "Vector.h"
#include <cmath>
#include "LeastSquares.h"


static Vector b(3,std::vector<double> {1,2,3});

auto GradientDescent(const Vector& x0, double step_size = 1, double tol = 1e-6, size_t max_iter=100){

 //Setup initialization variables
  Vector x(x0); // set the x values equal to our initial guess
  Vector g{gf(x,b)}; //create gradient from initial values

  auto obj(f(x,b));
  auto err(Vector::norm(g));
  // History of gradient descent, will be used to see the speed of convergence
  Vector err_his{max_iter + 1};
  Vector::zeroize(err_his);

  err_his(0) = err;

  //Start gradient descent iterations
  int iter_count{0};
  while (err >= tol){
    //gradient descent step
    x -= step_size*g;

    //update function and gradient
    g = gf(x,b);

    obj = f(x,b);
    err = Vector::norm(g);

    iter_count++;
    err_his(iter_count) = err;
    if (iter_count>=max_iter){
      std::cout << "Gradient descent reached maximum number of iterations.\n";
      std::cout << iter_count;
      std::cout << err;
      return x;
    }
  }
  return x;
}


int main() {
  Vector x0(3);
  Vector::zeroize(x0);
  Vector x(GradientDescent(x0));
  std::cout << x << "\n";
  return 0;
}

