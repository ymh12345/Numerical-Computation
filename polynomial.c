#include <stdio.h>
#include <time.h>
double my_pow(double x, int n);
double direct_poly(double x);


int main()
{
    double a, t1, t2;
    t1 = clock();
    a = direct_poly(2);
    t2 = clock();
    printf("%lf\n%lf", a, (t2-t1)/CLOCKS_PER_SEC);
    return 0;
}


double direct_poly(double x)
{
    double a[6] = {0.00125, 0.0626, 0.435, 1.2215, 1.912, 2.196};
    register double rlt = 0;
    register double tmp;
    for(int i = 1; i <= 6; i++){
        tmp = a[6-i] * my_pow(x, i-1);
        rlt += tmp;
    }
    return rlt;
}


double my_pow(double x, int n)
{
    if(n == 0)
        return 1;
    else
        return x * my_pow(x, n-1);
}