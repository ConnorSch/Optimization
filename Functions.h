//
// Created by Connor Schleicher on 11/4/21.
//

#ifndef OPTIMIZATION_FUNCTIONS_H
#define OPTIMIZATION_FUNCTIONS_H

#include "Vector.h"
#include <cmath>

class Functions{
public:
    enum Func {
        LeastSquares,
        LogRegression,
        max_funcs
    };
private:
  Func m_type{};
public:
    Functions(Func type):m_type(type){}

    template<class T>
    double f(T& x, const T& b){
      switch (m_type) {
        case LeastSquares:
          return 0.5*std::pow(((x-b).norm()),2);
      }
    }

    template<class T>
    T gf(T& x, const T& b){
      switch (m_type) {
        case LeastSquares:
          return (x-b);
      }
    }

    template<class T>
    T hf(T& x, const T& b){
      switch (m_type) {
        case LeastSquares:
          return 1.0;
      }
    }
};
#endif //OPTIMIZATION_FUNCTIONS_H
