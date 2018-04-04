#include <iostream>
#include <cmath>

using fptr = double(double);

void bissection (double xl, double xu,double eps, int Nmax, fptr f);
double f (double x);

int main (void)
{
  const double eps =1.0e-8;
  int Nmax =50;
  double xl=12, xu=18, xr=0;
  bissection (xl, xu, eps,  Nmax, f);

  return 0;
}

void bissection(double xl, double xu,double eps, int Nmax, fptr f)
  {
  
  double xr=0;
  for (double ii=0; ii<=Nmax; ++ii){
    xr=0.5*(xu+xl);
    std::cout << ii <<"\t"<< xr<<std::endl;
    if(std::fabs(f(xr)) <eps) break;
    if(f(xr)*f(xl) <0)
      xu = xr;
    else
      xl = xr;
  }

  return;
}

double f(double x)
{
  return (9.81*68.1/x)*(1-std::exp(-10*x/68.1)) -40; 
}
