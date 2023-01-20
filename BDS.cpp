#include <iostream>
#include <cmath>
#include <tuple>
#include "OptimizationAlgorithms.h"


#define H 1
#define X0 1
#define NMAX 100


double test_fun(double x)
{
    return (x-2)*(x-3);
}

int main()
{
    std::tuple<double, double> limits;
    limits=BDS(H, X0, NMAX, &test_fun,0);
    std::cout<<"Poczatek przedzialu: "<<std::get<0>(limits)<<"\n";
    std::cout<<"Koniec przedzialu: "<<std::get<1>(limits)<<"\n";
    return 0;

}
