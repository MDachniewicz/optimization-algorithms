#include<iostream>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<conio.h>


#define PI 3.14159265358979323846
#define TMAX 1.0
#define DELTA 0.0001

using namespace std;

double test_fun(double x)
{
    return (x+(1/pow(x,2)));
}

double norm_dist_box_muller(double median, double std_dev)
{
    double r1,r2;
    r1 = (double)rand()/(RAND_MAX+1);
    r2 = (double)rand()/(RAND_MAX+1);
    return std_dev * sqrt(-2*log(r1))*cos(2*PI*r2) + median;
}

double neighbour(double x, double t, double a, double b)
{
    double x1;
    x1=norm_dist_box_muller(x, t);
    if(x1<a)
    {
        return a;
    }
    else if(x1>b)
    {
        return b;
    }
    else
    {
        return x1;
    }
}

double start_point(double a, double b)
{
    return a+(double) rand() / ((double)RAND_MAX/(b-a));
}

double random01()
{
    return (double)rand()/(RAND_MAX+1);
}

double simulated_annealing(double (*func)(double), double tmax, double delta, double a=0, double b=1)
{
    double t,diff,x,x1;
    t=tmax;
    x=start_point(a,b);
    //printf("t= %f, x= %f \n", t, x);
    while(t>0.00000001)
    {
        x1=neighbour(x,t,a,b);
        diff=func(x1)-func(x);
        if(diff<0)
        {
            x=x1;
        }
        else
        {
            if(exp(-diff/t)>random01())
            {
                x=x1;
            }

        }
        //printf("t= %f, x= %f \n", t, x);
        t=t-delta*t;

    }
    return x;
}

int main()
{
    srand( (unsigned)time(NULL));

    cout<<start_point(0, 2)<<endl;
    cout<<simulated_annealing(&test_fun, TMAX, DELTA, 0, 2)<<endl;

    return 0;
}
