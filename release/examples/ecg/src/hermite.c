#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <hermite.h>


// N = order
// sigma = scale factor.
// x = point at which the polynomial is to be computed.
double hermitePolynomial(int N, double x)
{
	double ret_val = 0.0;
	if(N == 0)
		ret_val = 1;
	else if(N == 1)
		ret_val = 2.0 * x;
	else 
	{
		double H_1 = (2.0 * x * hermitePolynomial(N-1, x));
		double H_2 = (2.0 * (N-1) * hermitePolynomial(N-2, x));
		ret_val = H_1 - H_2;
	}
	return(ret_val);
}

double nFactor(int N)
{
	double ret_val = 1.0;
	if(N > 0)
	{
		ret_val = nFactor(N-1) * 1.0 / sqrt(2 * N);
	}
	return(ret_val);
}

double basisScaleFactor(int N, double sigma, double x)
{
	double ret_val = 1.0;
	double exp_factor  = pow(M_E, -(pow(x,2.0)/ (2.0 * pow (sigma, 2.0))));
	double denom_1 = 1.0/sqrt(sigma * sqrt(M_PI));
	double denom_2 = nFactor(N);
	return(exp_factor * denom_1 * denom_2);
}

double hermiteBasisFunction(int N, double sigma, double x)
{
	double ret_val = basisScaleFactor(N,sigma,x) *  hermitePolynomial(N,x);
	return(ret_val);
}


