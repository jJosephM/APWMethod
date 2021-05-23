#include "SphericalHarmonic.h"

#define PI 3.1415926536

unsigned int factorial(int f) //Calculates a factorial
{
	int fact = 1;
	for (int i = 2; i <= f; ++i)
	{
		fact = fact * i;
	}
	return fact;
}

double computeP(int l, int m, double theta) //Compute by recurrence relation
{
	double x = cos(theta),y = sin (theta), a,b;
	double P[l + 1];
	P[0] = 1 / sqrt(2 * PI); // First polynomial
	if (m = 0)
	{
		P[1] = x * sqrt(3 / 4 * PI);
		for (int i = 2; i < (l + 1); ++i)
		{
			a = sqrt((4 * i*i - 1) / (i*i - m));
			b = sqrt((i - 1)*(i - 1) / (4 * (i - 1)*(i - 1) - 1));
			P[m + i] = a * (x * P[i - 1] - b * P[i - 2]);
		}
	}
	else
	{
		P[1] = (-1) * sqrt(1 - x*x) * sqrt(3 / 4 * PI); // First diagonal polynomial
		for (int i = 2; i < (m + 1); ++i) //Polynomials when m = l, here i = l = m -- diagonals
		{	
			a = (-1) * sqrt(1 + 1 / (2 * m));
			P[i] = a * y * P[i - 1];
		}	
		if (l > m && m != 0) // The most general case
			P[m + 1] = sqrt(2 * m + 3) * x * P[m]; //Polynomial when m = m and l = m + 1
		for (int i = 2; i < (l - m + 1); ++i) //Polynomials when m = m and i = l - m
		{
			a = sqrt((4 * (i + m)*(i + m) - 1) / ((i + m)*(i + m) - m));
			b = sqrt(((i + m - 1)*(i + m - 1) - m*m) / (4 * (i + m - 1)*(i + m - 1) -1));
			P[m + i] = a * (x * P[i - 1] - b * P[i - 2]);
		}
	}
	return P[l];
}

double computeAzim(double phi, int m, bool is_sine) //if sin == false, then compute cosine
{
	double psi = (m - 1) * phi, alpha = 2 * pow(sin(phi / 2),2), beta = sin(phi), azim;
	if (is_sine)
		azim = sin(psi) - alpha * sin(psi) + beta * cos(psi);
	else
		azim = cos(psi) - alpha * cos(psi) - beta * sin(psi);
	return azim;
}

double SphH(int l,int m,double theta,double phi)
{
	if (m < 0)
	{
		m = abs(m);
		return computeP(l,m,theta) * computeAzim(phi,m, 1);
	}
	else if (m == 0)
	{
		return computeP(l,m,theta) * (1 / sqrt(2));
	}
	else
	{
		return computeP(l,m,theta) * computeAzim(phi,m, 0);
	}
}