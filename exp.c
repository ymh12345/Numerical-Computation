#include <stdio.h>
#define e 2.7118281828

double my_exp(double x, int n);
int factorial(int x);
double my_pow(double x, int n);


int main()
{
    int i;
    register double error, t;
    for(i=0;i<10;i++){
        t = my_exp(1, i);
        error = t - e;
        printf("%.10lf\n", error);
    }
}


double my_exp(double x, int n)
{
    int i;
    double rlt=0;
    for(i=0;i<=n;i++){
        double tmp = my_pow(x, i) / factorial(i);
        rlt += tmp;
    }
    return rlt;
}

int factorial(int x)
{
    if(x==0)
        return 1;
    else
        return x * factorial(x-1);
}

double my_pow(double x, int n)
{
    if(n == 0)
        return 1;
    else
        return x * my_pow(x, n-1);
}
