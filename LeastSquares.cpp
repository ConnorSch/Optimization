//
// Created by Connor Schleicher on 10/29/21.
//
#include "Vector.h"
#include <cmath>

double f(Vector& x,const Vector& b) {return 0.5*std::pow(((x-b).norm()),2);}
Vector gf(Vector& x,const Vector& b) {return (x-b);}
double hf(Vector& x,const Vector& b) {return 1;}