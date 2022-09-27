#include<stdio.h>
#include <iostream>
#include<cmath>
#define H 1
#define X0 1
#define NMAX 100

using namespace std;

float test_fun(float x)
{
    return (x-2)*(x-3);
}

void BDS(float h, float x0, int Nmax, float (*func)(float))
{
    float i=0;
    float xi1, xi;


    xi=x0;
    xi1=x0+pow(2, i)*h;
    while(func(xi1)<func(xi))
    {
        i++;
        xi=xi1;
        xi1=x0+pow(2, i)*h;

        if(i>Nmax)
        {
            printf("Error");
        }
    }




    printf("b=%f \n",xi1);
    //return 0;


    i=0;
    xi=x0;
    xi1=x0-pow(2, i)*h;
    while(func(xi1)<func(xi))
    {
        i++;
        xi=xi1;
        xi1=x0-pow(2, i)*h;

        if(i>Nmax)
        {
            printf("Error");
        }
    }
    printf("f(%f)=%f \n",xi, func(xi));
    printf("a=%f \n",xi1);
}

int main()
{
    float x;
    printf("%f, %f, %f \n", test_fun(0), test_fun(1), test_fun(2));
    BDS(H, X0, NMAX, &test_fun);
    return 0;

}
