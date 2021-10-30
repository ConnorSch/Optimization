//
// Created by Connor Schleicher on 10/29/21.
//
#include "Vector.h"
#include <cmath>

Vector f(Vector& x, Vector& b) {return 0.5*std::pow(Vector::sum(Vector::norm(x-b)),2);}
Vector gf(Vector& x, Vector& b) {return (x-b);}
double hf(Vector& x, Vector& b) {return 1;}