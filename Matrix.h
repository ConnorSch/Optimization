//
// Created by Connor Schleicher on 10/27/21.
//

#ifndef OPTIMIZATION_MATRIX_H
#define OPTIMIZATION_MATRIX_H

#include <vector>
#include "Vector.h"

class Matrix {
private:
    size_t m_num_rows{}, m_num_cols{};
    std::vector<double> m_storage{};
public:
    Matrix(size_t rows, size_t cols)
    : m_num_rows{rows},
      m_num_cols{cols},
      m_storage(m_num_cols * m_num_rows)
      {};

          double& operator()(size_t i, size_t j)       {return m_storage[i * m_num_cols + j];}
    const double& operator()(size_t i, size_t j) const {return m_storage[i * m_num_cols + j];}

          Vector  operator()(size_t col){
            Vector t(m_num_rows);
            size_t counter{0};;
            for (int j = col; j < m_num_cols*m_num_rows; j+=m_num_cols) {
              t(counter) = m_storage[j];
              counter++;
            }
            return t;
          };

    const Vector operator()(size_t col) const {
            Vector t(m_num_rows);
            size_t counter{0};;
            for (int j = col; j < m_num_cols*m_num_rows; j+=m_num_cols) {
              t(counter) = m_storage[j];
              counter++;
            }
            return t;
          };

    friend Matrix operator+(const Matrix& A, const Matrix& B);
    friend Matrix operator-(const Matrix& A, const Matrix& B);
    friend Vector operator*(const Matrix& A, const Vector& B);
    friend Matrix operator*(const Matrix& A, const Matrix& B);
    friend Matrix operator-=(Matrix& A, const Matrix& B){return A - B;}

    friend std::ostream& operator<< (std::ostream& out, const Matrix& A) {
      for (int i = 0; i < A.num_rows(); ++i) {
        for (int j = 0; j < A.num_cols(); ++j) {
          out << A(i,j) << ' ';
        }
        out << "\n";
      }
      return out;
    }

    friend void matmul(const Matrix& A, const Matrix& B, Matrix& C);
    friend void unitize(Matrix& A);

    size_t num_rows() const {return m_num_rows;}
    size_t num_cols() const {return m_num_cols;}
    size_t size() const {return m_num_rows*m_num_cols;}
};


#endif //OPTIMIZATION_MATRIX_H
