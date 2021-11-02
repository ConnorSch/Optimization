//
// Created by Connor Schleicher on 11/1/21.
//

#ifndef OPTIMIZATION_LEASTSQUARES_H
#define OPTIMIZATION_LEASTSQUARES_H

#include "Vector.h"
double f(Vector& x,const Vector& b);
Vector gf(Vector& x,const Vector& b);
double hf(Vector& x,const Vector& b);

#endif //OPTIMIZATION_LEASTSQUARES_H
