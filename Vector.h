//
// Created by Connor Schleicher on 10/27/21.
//

#ifndef OPTIMIZATION_VECTOR_H
#define OPTIMIZATION_VECTOR_H

#include <vector>
#include <iostream>

class Vector {

private:
    size_t              m_num_rows;
    std::vector<double> m_storage;

public:
    Vector(size_t M) : m_num_rows(M), m_storage(m_num_rows) {}
    Vector(size_t M,std::vector<double> nums) : m_num_rows(M), m_storage(nums){};

          double& operator()(size_t i)       {return m_storage[i];}
    const double& operator()(size_t i) const {return m_storage[i];}

    friend Vector operator-(const Vector& x, const Vector& y);

    size_t num_rows() const {return m_num_rows;}

    static void zeroize(Vector& x);

    friend std::ostream& operator<< (std::ostream& out, const Vector& v) {
      for (int i = 0; i < v.num_rows(); ++i) {
        out << v(i) << ' ';
      }
      return out;
    }

    static double norm(const Vector& v);
    static double sum(const Vector& x);
};


#endif //OPTIMIZATION_VECTOR_H
