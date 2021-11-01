//
// Created by Connor Schleicher on 11/1/21.
//

#ifndef OPTIMIZATION_LEASTSQUARES_H
#define OPTIMIZATION_LEASTSQUARES_H

#include "Vector.h"
Vector f(Vector& x, Vector& b);
Vector gf(Vector& x, Vector& b);
double hf(Vector& x, Vector& b);

#endif //OPTIMIZATION_LEASTSQUARES_H
