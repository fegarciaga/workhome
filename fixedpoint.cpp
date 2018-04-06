#include <iostream>
#include <cmath>

using fptr = double(double);

void fixedpoint (double a, double eps, int Nmax, fptr f);
double f(double x);
double g(double x);

int main (void)
{
  const double a =0.0;
  const double eps =1.0e-8;
  const int Nmax =50;
  fixedpoint (a, eps, Nmax, f);
  
  return 0;
}

void fixedpoint (double a, double eps, int Nmax, fptr f)
{
  for (double ii=0; ii<=Nmax; ++ii){
    std::cout<<ii<<"\t"<<a<<"\n";
    if(std::fabs(f(a))<eps) break;
    else
      a=g(a);
  }
  return ;
}

double f(double x)
{
  return (std::exp(-x))-x;
}

double g(double x)
{
  return std::exp(-x);
}
