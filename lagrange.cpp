#include<iostream>
#include<cmath>

#define eps 0.01
#define gamma 0.0001
#define NMAX 100



double test_fun(double x)
{
    return (x+(1/pow(x,2)));
}

void lagrange(double a0, double b0, double c0, double (*func)(double))
{
    int i=0;
    double ai1,bi1,ci1,di1;
    double ai=a0,bi=b0,ci=c0,di;
    di=c0;

    do
    {

        di1=di;
        di=0.5*(func(ai)*(pow(ci,2)-pow(bi,2))+func(ci)*(pow(bi,2)-pow(ai,2))+func(bi)*(pow(ai,2)-pow(ci,2)))/(func(ai)*(ci-bi)+func(ci)*(bi-ai)+func(bi)*(ai-ci));


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
                printf("The algorithm does not converge. \n");
                break;
            }
        }
        i++;
        ai=ai1;
        bi=bi1;
        ci=ci1;
        if(i>NMAX)
        {
            printf("Accuracy not achieved. \n");
            break;
        }


    std::cout<<"i=" <<i<<", ai= " << ai<<", bi= "<<bi<<", ci= "<<ci<<", di= "<<di<<", di-1= "<<di1<<std::endl;
    }while( !((bi-ai)<eps || fabs(di-di1)<=gamma));

    std::cout<<"Result: "<< di<<std::endl;

}

int main()
{
    double a0=1,b0=2,c0=1.5;
    lagrange(a0, b0, c0, &test_fun);
    return 0;

}
