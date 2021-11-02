//
// Created by Connor Schleicher on 11/1/21.
//

#ifndef OPTIMIZATION_ALGORITHMS_H
#define OPTIMIZATION_ALGORITHMS_H
#include "Vector.h"

class Algorithms {
public:
    enum Algorithm{
        GD,
        NR,
        max_algorithms
    };
private:
    Algorithm m_type{};
    double step_size{1};
    size_t max_iter{100};
    double tol{1e-6};
    Vector m_obj_his{max_iter + 1};
    Vector m_err_his{max_iter + 1};
public:
    Algorithms(Algorithm type) : m_type(type){}

    Vector GradientDescent(const Vector& x0, const Vector& b);

    Vector get_obj_his() const {return m_obj_his;}
    Vector get_err_his() const {return m_err_his;}
};


#endif //OPTIMIZATION_ALGORITHMS_H
