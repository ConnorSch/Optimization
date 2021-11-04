//
// Created by Connor Schleicher on 11/1/21.
//

#ifndef OPTIMIZATION_ALGORITHMS_H
#define OPTIMIZATION_ALGORITHMS_H
#include "Vector.h"
#include "Functions.h"

class Algorithms {
public:
    enum Algorithm{
        GD,
        NR,
        max_algorithms
    };
private:
    Algorithm m_type{};
    double m_step_size{};
    size_t m_max_iter{};
    double m_tol{};
    Vector m_obj_his{};
    Vector m_err_his{};
    size_t m_iter_count{0};
public:
    Algorithms(Algorithm type,double step_size = 1, size_t max_iter = 100, double tol = 1e-6) :
    m_type(type),
    m_step_size(step_size),
    m_max_iter(max_iter),
    m_tol(tol),
    m_obj_his(max_iter + 1),
    m_err_his(max_iter + 1)
    {
      m_obj_his.zeroize();
      m_err_his.zeroize();
    }

    template<typename T>
    T GradientDescent(const T& x0, const T& b, Functions func);

    template<typename T>
    T NewtonRaphson(const T& x0, const T& b, Functions func);

    Vector get_obj_his() const {
      Vector t(m_iter_count);
      for (int i = 0; i < m_iter_count; ++i) {
        t(i) = m_obj_his(i);
      }
      return t;
    }
    Vector get_err_his() const {
      Vector t(m_iter_count);
      for (int i = 0; i < m_iter_count; ++i) {
        t(i) = m_err_his(i);
      }
      return t;
    }
};

template<typename T>
T Algorithms::GradientDescent(const T& x0, const T& b, Functions func){

  //Setup initialization variables
  T x(x0); // set the x values equal to our initial guess
  T g{func.gf(x,b)}; //create gradient from initial values

  double obj((func.f(x, b)));
  auto err(g.norm());


  m_err_his(0) = err;
  m_obj_his(0) = obj;
  //Start gradient descent iterations
  int iter_count{0};
  while (err >= m_tol){
    //gradient descent step
    x -= m_step_size*g;

    //update function and gradient
    g = func.gf(x,b);

    obj = func.f(x,b);
    err = g.norm();

    iter_count++;
    m_err_his(iter_count) = err;
    m_obj_his(iter_count) = obj;
    if (iter_count>=m_max_iter){
      std::cout << "Gradient descent reached maximum number of iterations.\n";
      std::cout << iter_count;
      std::cout << err;
      m_iter_count = iter_count;
      return x;
    }
  }
  m_iter_count = iter_count;
  return x;
}

template<typename T>
T Algorithms::NewtonRaphson(const T &x0, const T &b, Functions func) {
  //Setup initialization variables
  T x(x0); // set the x values equal to our initial guess
  T g{func.gf(x,b)}; //create gradient from initial values
  T h{1}; //TODO update with actual Hessian function

  double obj(func.f(x,b));
  auto err(g.norm());


  m_err_his(0) = err;
  m_obj_his(0) = obj;
  //Start gradient descent iterations
  int iter_count{0};
  while (err>= m_tol){
    x -= g; //TODO fix this step. Need to implement linear solver for form Ax = b. Correct line should read x -= solve(H,g)

    //perform updates
    g = func.gf(x,b);
    obj = func.f(x,b);
    err = g.norm();

    iter_count++;
    m_err_his(iter_count) = err;
    m_obj_his(iter_count) = obj;
  }
  m_iter_count = iter_count;
  return x;
}

#endif //OPTIMIZATION_ALGORITHMS_H
