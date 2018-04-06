#include <iostream>
#include <cmath>

using fptr = double(double);

void newton (double a, double eps, int Nmax, fptr f);
double derive (fptr f, double eps, double x);
double f(double x);

int main (void)
{
  const double a=0.0;
  const double eps=1.0e-8;
  const int Nmax=50;
  newton (a, eps, Nmax, f);

  return 0;
}

void newton (double a, double eps, int Nmax, fptr f)
{
  for (int ii=1;ii<=Nmax; ii++){
    std::cout<<ii<<"\t"<<a<<"\n";
    if (std::fabs(f(a))<eps) break;
    else
      a=a-(f(a)/derive(f, eps, a));
  }
  return ;
}

double derive (fptr f, double eps, double x)
{
  return (f(x+eps)-f(x))/eps;
}

double f(double x)
{
  return std::exp(-x)-x;
}
