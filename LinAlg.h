//
// Created by Connor Schleicher on 11/9/21.
//

#ifndef OPTIMIZATION_LINALG_H
#define OPTIMIZATION_LINALG_H

#include "Vector.h"
#include "Matrix.h"

Matrix LUFactor(const Matrix& A){
  Matrix U(A);
  Matrix L(A.num_rows(), A.num_cols());
  unitize(L);
  Matrix P(L);
  for (int k = 0; k < A.num_rows() -1; ++k) {
    ;
  }
  return L;
}

Matrix QR(const Matrix& A){
  Matrix r(A.num_rows(), A.num_cols());
  Matrix q(A.num_rows(), A.num_cols());
  Matrix V(A);
  for (int i = 0; i < A.num_cols(); ++i) {
    r(i,i) = V(i).norm();
    Vector v = V(i);
    for (int k = 0; k < v.num_rows(); ++k) {
      q(k,i) = v(k)/r(i,i);
    }
    for (int j = i + 1; j < A.num_cols(); ++j) {
      r(i,j) = q(i)*V(j); //needs to be q transpose
      V(j) = V(j) - r(i,j)*q(i);
    }
  }
  std::cout << r << "\n";
  return q;
}


#endif //OPTIMIZATION_LINALG_H
