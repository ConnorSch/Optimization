//
// Created by Connor Schleicher on 10/27/21.
//

#ifndef OPTIMIZATION_MATRIX_H
#define OPTIMIZATION_MATRIX_H

#include <vector>

class RowMatrix {
private:
    size_t m_num_rows{}, m_num_cols{};
    std::vector<double> m_storage{};
public:
    RowMatrix(size_t rows, size_t cols)
    : m_num_rows{rows},
      m_num_cols{cols},
      m_storage(m_num_cols * m_num_rows)
      {};

          double& operator()(size_t i, size_t j)       {return m_storage[i * m_num_cols + j];}
    const double& operator()(size_t i, size_t j) const {return m_storage[i * m_num_cols + j];}

    size_t num_rows() const {return m_num_rows;}
    size_t num_cols() const {return m_num_cols;}
};


#endif //OPTIMIZATION_MATRIX_H
