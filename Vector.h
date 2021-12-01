//
// Created by Connor Schleicher on 10/27/21.
//

#ifndef OPTIMIZATION_VECTOR_H
#define OPTIMIZATION_VECTOR_H

#include <vector>
#include <iostream>
#include <algorithm>

class Vector {

private:
    size_t              m_num_rows;
    std::vector<double> m_storage;

public:
    Vector() = default;
    Vector(size_t M) : m_num_rows(M), m_storage(m_num_rows) {}
    Vector(size_t M,std::vector<double> nums) : m_num_rows(M), m_storage(nums){};

          double& operator()(size_t i)       {return m_storage[i];}
    const double& operator()(size_t i) const {return m_storage[i];}

    friend Vector operator-(const Vector& x, const Vector& y){
      Vector z(x.num_rows());
      for (int i = 0; i < x.num_rows(); ++i) {
        z(i) = x(i) - y(i);
      }
      return z;
    }
    friend Vector operator*(double d, const Vector& x){
      Vector y{x.num_rows()};
      for (int i = 0; i < x.num_rows(); ++i) {
        y(i) = d*x(i);
      }
      return y;
    }
    friend double operator*(const Vector& A, const Vector& B){
      double result{0};
      for (int i = 0; i < A.num_rows(); ++i) {
        result += A(i) * B(i);
      }
      return result;
    }
    friend Vector operator-=(Vector& x, const Vector& y){x = x-y; return x;}

    friend Vector operator/(Vector& x, double y){
      Vector z{x.num_rows()};
      for (int i = 0; i < x.num_rows(); ++i) {
        z(i) = x(i)/y;
      }
      return z;
    }

    friend std::ostream& operator<< (std::ostream& out, const Vector& v) {
      for (int i = 0; i < v.num_rows(); ++i) {
        out << v(i) << ' ';
      }
      return out;
    }

    size_t num_rows() const {return m_num_rows;}

    void zeroize();
    void unitize();

    double norm();
    double sum();
};


#endif //OPTIMIZATION_VECTOR_H
