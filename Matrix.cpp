//
// Created by Connor Schleicher on 10/27/21.
//

#include "Matrix.h"
void unitize(Matrix& A){
  for (int i = 0; i < A.num_rows(); ++i) {
    A(i,i) = 1;
  }
}

Matrix operator+(const Matrix& A, const Matrix& B){
  assert(A.num_rows() == B.num_rows());
  assert(A.num_cols() == B.num_cols());
  Matrix C(A.num_rows(), A.num_cols());
  for (int i = 0; i < A.num_rows(); ++i) {
    for (int j = 0; j < A.num_cols(); ++j) {
      C(i,j) = A(i,j) + B(i,j);
    }
  }
  return C;
}

Matrix operator-(const Matrix& A, const Matrix& B){
  assert(A.num_rows() == B.num_rows());
  assert(A.num_cols() == B.num_cols());
  Matrix C(A.num_rows(), A.num_cols());
  for (int i = 0; i < A.num_rows(); ++i) {
    for (int j = 0; j < A.num_cols(); ++j) {
      C(i,j) = A(i,j) - B(i,j);
    }
  }
  return C;
}

void mult(const Matrix& A, const Vector& x, Vector& y) {
  assert(y.num_rows() == A.num_rows());
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < A.num_cols(); ++j) {
      y(i) += A(i, j) * x(j);
    }
  }
}

Vector operator*(const Matrix& A, const Vector& x) {
  Vector y(A.num_rows());
  mult(A, x, y);
  return y;
}

//single threaded matrix multiplications
//does add in blocking hoisting and tiling for modest performance improvements
void matmul(const Matrix& A, const Matrix& B, Matrix& C){
  assert(A.num_rows() == C.num_rows());
  assert(B.num_cols() == C.num_cols());
  assert(A.num_cols() == B.num_rows());

  size_t blocksize = 32; //fairly arbitrary block size, should fit in L1/L2 memory
  for (size_t ii = 0; ii < C.num_rows(); ii += blocksize) {
    for (size_t jj = 0; jj < C.num_cols(); jj += blocksize) {
      for (size_t kk = 0; kk < A.num_cols(); kk += blocksize) {

        size_t stop_i = std::min(ii + blocksize, C.num_rows());
        size_t stop_j = std::min(jj + blocksize, C.num_cols());
        size_t stop_k = std::min(kk + blocksize, A.num_cols());

        for (size_t i = ii; i < stop_i; i += 2) {
          for (size_t j = jj; j < stop_j; j += 2) {

            double t00 = C(i, j);
            double t01 = C(i, j + 1);
            double t10 = C(i + 1, j);
            double t11 = C(i + 1, j + 1);

            for (size_t k = kk; k < stop_k; ++k) {
              t00 += A(i, k) * B(k, j);
              t01 += A(i, k) * B(k, j + 1);
              t10 += A(i + 1, k) * B(k, j);
              t11 += A(i + 1, k) * B(k, j + 1);
            }

            C(i, j)         = t00;
            C(i, j + 1)     = t01;
            C(i + 1, j)     = t10;
            C(i + 1, j + 1) = t11;
          }
        }
      }
    }
  }
}

Matrix operator*(const Matrix& A, const Matrix& B){
  Matrix C(A.num_rows(), B.num_cols());
  matmul(A,B,C);
  return C;
}