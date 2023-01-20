#ifndef OPTIMIZATIONALGORITHMS_H_INCLUDED
#define OPTIMIZATIONALGORITHMS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <tuple>

//namespace OA
//{
    std::tuple<double, double> BDS(double h, double x0, int Nmax, double (*func)(double), bool verbose=1);

    double lagrange(double a0, double b0, double c0, double (*func)(double), bool verbose=1, int nmax=100, double gamma=0.0001, double eps=0.01);

//}



#endif // OPTIMIZATIONALGORITHMS_H_INCLUDED
