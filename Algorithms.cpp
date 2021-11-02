//
// Created by Connor Schleicher on 11/1/21.
//

#include "Algorithms.h"
#include "LeastSquares.h"

Vector Algorithms::GradientDescent(const Vector& x0, const Vector& b){

  //Initialize err_his and obj_his
  m_err_his.zeroize();
  m_obj_his.zeroize();

  //Setup initialization variables
  Vector x(x0); // set the x values equal to our initial guess
  Vector g{gf(x,b)}; //create gradient from initial values

  double obj(f(x,b));
  auto err(g.norm());


  m_err_his(0) = err;
  m_obj_his(0) = obj;
  //Start gradient descent iterations
  int iter_count{0};
  while (err >= tol){
    //gradient descent step
    x -= step_size*g;

    //update function and gradient
    g = gf(x,b);

    obj = f(x,b);
    err = g.norm();

    iter_count++;
    m_err_his(iter_count) = err;
    m_obj_his(iter_count) = obj;
    if (iter_count>=max_iter){
      std::cout << "Gradient descent reached maximum number of iterations.\n";
      std::cout << iter_count;
      std::cout << err;
      return x;
    }
  }
  return x;
}