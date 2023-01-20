#include <iostream>
#include <cmath>
#include <tuple>
#include "OptimizationAlgorithms.h"

std::tuple<double, double> BDS(double h, double x0, int nmax, double (*func)(double), bool verbose)
{
    double i=0;
    double xi1, xi,a,b;
    xi=x0;
    xi1=x0+std::pow(2, i)*h;
    while(func(xi1)<func(xi))
    {
        i++;
        xi=xi1;
        xi1=x0+std::pow(2, i)*h;

        if(i>nmax)
        {
            std::cout<<"Error"<<std::endl;
        }
    }
    if(verbose==1)
    {
        std::cout<<"b="<<xi1<<std::endl;
    }
    b=xi1;
    i=0;
    xi=x0;
    xi1=x0-std::pow(2, i)*h;
    while(func(xi1)<func(xi))
    {
        i++;
        xi=xi1;
        xi1=x0-std::pow(2, i)*h;

        if(i>nmax)
        {
            std::cout<<"Error"<<std::endl;
        }
    }
    if(verbose==1)
    {
        //std::cout<<"f("<<xi<<")="<<func(xi)<<std::endl;
        std::cout<<"a="<<xi1<<std::endl;
    }
    a=xi1;
    return std::make_tuple(a,b);
}


double lagrange(double a0, double b0, double c0, double (*func)(double), bool verbose, int nmax, double gamma, double eps)
{
    int i=0;
    double ai1,bi1,ci1,di1;
    double ai=a0,bi=b0,ci=c0,di;
    di=c0;
    do
    {
        di1=di;
        di=0.5*(func(ai)*(std::pow(ci,2)-std::pow(bi,2))+func(ci)*(std::pow(bi,2)-std::pow(ai,2))+func(bi)*(std::pow(ai,2)-std::pow(ci,2)))
            /(func(ai)*(ci-bi)+func(ci)*(bi-ai)+func(bi)*(ai-ci));
        if((ai<di) && (di<ci))
        {
            if(func(di)<func(ci))
            {
                ai1=ai;
                ci1=di;
                bi1=ci;
            }
            else
            {
                ai1=di;
                ci1=ci;
                bi1=bi;
            }
        }
        else
        {
            if((ci<di) && (di<bi))
            {
                if(func(di)<func(ci))
                {
                    ai1=ci;
                    ci1=di;
                    bi1=bi;
                }
                else
                {
                    ai1=ai;
                    ci1=ci;
                    bi1=di;
                }
            }
            else
            {
                std::cout<<"The algorithm does not converge."<<std::endl;
                break;
            }
        }
        i++;
        ai=ai1;
        bi=bi1;
        ci=ci1;
        if(i>nmax)
        {
            std::cout<<"Accuracy not achieved."<<std::endl;
            break;
        }
    std::cout<<"i=" <<i<<", ai= " << ai<<", bi= "<<bi<<", ci= "<<ci<<", di= "<<di<<", di-1= "<<di1<<std::endl;
    }while( !((bi-ai)<eps || std::abs(di-di1)<=gamma));
    std::cout<<"Result: "<< di<<std::endl;
    return di;
}

