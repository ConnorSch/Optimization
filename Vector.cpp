//
// Created by Connor Schleicher on 10/27/21.
//

#include "Vector.h"
#include <cmath>

void Vector::zeroize() {
  for (int i = 0; i < m_num_rows; ++i) {
    m_storage[i] = 0.0;
  }
}

void Vector::unitize() {
  for (int i = 0; i < m_num_rows; ++i) {
    m_storage[i] = 1.0;
  }
}

double Vector::norm() {
  double norm{};
  for (int i = 0; i < m_num_rows; ++i) {
    norm += m_storage[i] * m_storage[i];
  }
  return sqrt(norm);
}

double Vector::sum(){
  double z{0};
  for (int i = 0; i < m_num_rows; ++i) {
    z += m_storage[i];
  }
  return z;
}