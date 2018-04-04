#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

void fderivforward (double a, double b, double h, std::string name);
void fderivcentral (double a, double b, double h, std::string name);
void fderivforwardrichardson (double a, double b, double h, std::string name);
void fderivcentralrichardson (double a, double b, double h, std::string name);

int main (void)
{
  fderivforward (-M_PI,M_PI, 0.1, "derivforward.txt");
  fderivcentral (-M_PI,M_PI, 0.1, "derivcentral.txt");
  fderivforwardrichardson (-M_PI,M_PI, 0.1, "derivforwardrichardson.txt");
  fderivcentralrichardson (-M_PI,M_PI, 0.1, "derivcentralrichardson.txt");

  return 0;
}

void fderivforward (double a, double b, double h, std::string name)
{
  std::ofstream fout(name);
  fout.precision (16);
  fout.setf(std::ios::scientific);
  for (a; a<=b; a=a+h){
    double result=0.0;
    result=(std::sin(a+h)-std::sin(a))/h;
    fout << a <<"\t"<< result <<"\n";
  }
  fout.close();
}
void fderivcentral (double a, double b, double h, std::string name)
{
  std::ofstream fout(name);
  fout.precision (16);
  fout.setf(std::ios::scientific);
  for (a; a<=b; a=a+h){
      double result=0.0;
      result=(std::sin(a+(h/2))-std::sin(a-(h/2)))/h;
      fout << a <<"\t"<< result <<"\n";
    }
    fout.close();
}
void fderivforwardrichardson (double a, double b, double h, std::string name)
{
  std::ofstream fout(name);
  fout.precision (16);
  fout.setf(std::ios::scientific);
  for(a; a<=b; a=a+h){
    double result1=0.0, result2=0.0, result=0.0;
    result1=(4/3)*(std::sin(a+(h/2))-std::sin(a))/(h/2);
    result2=(1/3)*(std::sin(a+h)-std::sin(a))/h;
    result= result1-result2;
    fout << a <<"\t"<< result <<"\n";
  }
  fout.close();
}
void fderivcentralrichardson (double a, double b, double h, std::string name)
{
  std::ofstream fout(name);
  fout.precision (16);
  fout.setf(std::ios::scientific);
  for (a; a<=b; a=a+h){
    double result1=0.0, result2=0.0, result=0.0;
    result1=(4/3)*(std::sin(a+(h/4))-std::sin(a-(h/4)))/(h/2);
    result2=(1/3)*(std::sin(a+(h/2))-std::sin(a-(h/2)))/h;
    result= result1-result2;
    fout << a <<"\t"<< result<<"\n";
  }
  fout.close();
}
