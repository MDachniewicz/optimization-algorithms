#include <random>
#include <iostream>
#include <cmath>



#define PI 3.14159265358979323846
#define TMAX 1.0
#define DELTA 0.0001

using namespace std;

random_device rd;
mt19937 gen(rd());

double test_fun(double x)
{
    return (x+(1/pow(x,2)));
}

double norm_dist(double median, double std_dev)
{
    normal_distribution<double> normal_dist(median, std_dev);
    return normal_dist(gen);
}

double neighbour(double x, double t, double a, double b)
{
    double x1;
    x1=norm_dist(x, t);
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
    uniform_real_distribution<> dist_ab(a,b);
    return dist_ab(gen);
}

double random01()
{
    uniform_real_distribution<> dist(0,1);
    return dist(gen);
}

double simulated_annealing(double (*func)(double), double tmax, double delta, double a=0, double b=1)
{
    double t,diff,x,x1;
    t=tmax;
    x=start_point(a,b);

    while(t>0.0001)
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




    cout<<start_point(0, 2)<<endl;
    cout<<simulated_annealing(&test_fun, TMAX, DELTA, 0, 2)<<endl;

    return 0;
}
