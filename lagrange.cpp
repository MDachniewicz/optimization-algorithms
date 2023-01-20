#include<iostream>
#include<cmath>
#include "OptimizationAlgorithms.h"


double test_fun(double x)
{
    return (x+(1/pow(x,2)));
}



int main()
{
    double a0=1,b0=2,c0=1.5;
    lagrange(a0, b0, c0, &test_fun);
    return 0;

}
