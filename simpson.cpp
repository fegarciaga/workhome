#include <iostream>
#include <vector>
#include <cmath>

using fptr = double(double);

double trapezoid_irregular(const std::vector<double> & x, const std::vector<double> & fx);
double trapezoid_regular(const double a, const double b, const int n, fptr func);
double trapezoid_richardson(const double a, const double b, const int n, fptr func);
double simpson(const double a, const double b, const int n, fptr func);

int main(void)
{
  const int N = 20;
  
  // test on-iregular (modelled regular to compare)
  std::vector<double> x(N), f(N);
  for (int ii = 0; ii < N; ++ii) {
    x[ii] = 0 + ii*(M_PI-0)/N;
    f[ii] = std::sin(x[ii]);
  }
  std::cout << "Non-regular integral is : " << trapezoid_irregular(x, f) << std::endl;
  
  // test on regular
  std::cout << "Regular integral (n = 20) is : " << trapezoid_regular(0, M_PI, 20, std::sin) << std::endl;
  std::cout << "Regular integral (n = 40) is : " << trapezoid_regular(0, M_PI, 40, std::sin) << std::endl;
  
  // test with Richardson
  std::cout << "Richardson integral (n = 20) is : " << trapezoid_richardson(0, M_PI, 20, std::sin) << std::endl;
  
  // test with Simpson
  std::cout << "Simpson integral (n = 20) is : " << simpson(0, M_PI, 20, std::sin) << std::endl;
  
  
  return 0;
}

double trapezoid_irregular(const std::vector<double> & x, const std::vector<double> & fx)
{
  double sum = 0.0;
  for (int ii = 0; ii < x.size() - 1; ++ii) { // note the upper limit
    sum += (x[ii + 1] - x[ii])*(fx[ii] + fx[ii+1]);
  }
  return 0.5*sum;
}

double trapezoid_regular(const double a, const double b, const int n, fptr func)
{
  const double h = (b-a)/n;
  double sum = 0.5*(func(a) + func(b));
  for(int ii = 1; ii <= n-1; ++ii) { // note limits
    double x = a + ii*h;
    sum += func(x);
  }
  return h*sum;
}

double trapezoid_richardson(const double a, const double b, const int n, fptr func)
{
  return (4*trapezoid_regular(a, b, 2*n, func) - trapezoid_regular(a, b, n, func))/3;
}

double simpson(const double a, const double b, const int n, fptr func)
{
  double sum = 0, result = func(a) + func(b);
  double x;
  const double h = (b-a)/n;
  
  sum = 0;
  for(int ii = 1; ii <= n/2 - 1; ++ii ) {
    x = a + 2*ii*h;
    sum += func(x);
  }
  result += 2*sum;
  sum = 0;
  for(int ii = 1; ii <= n/2; ++ii ) {
    x = a + (2*ii-1)*h;
    sum += func(x);
  }
  result += 4*sum;  
  
  return result*h/3;
}
