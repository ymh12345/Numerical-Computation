#include <stdio.h>
#include <time.h>
double my_pow(double x, int n);
double direct_poly(double x);
double horner(double x);


int main()
{
    //double a, t1, t2;
    //t1 = clock();
    //a = direct_poly(2);
    //t2 = clock();
	double a;
	a = horner(2);
    printf("%lf\n", a);
	system("pause");
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


double horner(double x)
{
	// QinJiuShao algorithm is called horner algorithm also.
	double a[6] = { 0.00125, 0.0626, 0.435, 1.2215, 1.912, 2.196 };
	double rlt = 0;
	for (int i = 6; i > 0; i--) {
		rlt += a[6 - i] * x;
	}
	return rlt;
}