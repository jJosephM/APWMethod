#ifndef SPHERICAL_HARMONIC_H
#define SPHERICAL_HARMONIC_H

#include <cmath>
#include <iostream>

#define PI 3.1415926536


unsigned int factorial(int i);

// void computCoeff(int l, int m, long double* A);

double computeP(int l, int m, double theta);

double computeAzim(double phi, int m, bool is_sin);

double SphH(int l,int m,double theta,double phi);

#endif