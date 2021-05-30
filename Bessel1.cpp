#include "Bessel1.h"

#define PI 3.1415926536

//This is the recursive code, not the Harrison code

double SphB(int l, double x)
{
    if (l == 0)
        return sin(x) / x;
    else if (l == 1)
        return sin(x) / pow(x,2) - cos(x) / x;
    else
    {
        double B[l];
        B[0] = sin(x) / x;
        B[1] = sin(x) / pow(x,2) - cos(x) / x;
        for (int i = 2; i < (l + 1); i++)
        {
            B[i] = (2 * (i - 1) / x) * B[i - 1] - B[i - 2];
        }
        return B[l];
    }
}