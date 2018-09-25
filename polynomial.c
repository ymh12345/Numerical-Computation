#include <stdio.h>
#include <time.h>
#include <unistd.h>

double my_pow(double x, int n);
double direct_poly(double x);
double horner(double x);


int main()
{
    double meantime1 = 0, meantime2 = 0;
    int i = 1;
    for(i = 1; i <= 10000; i++){
        double a, b, t1, t2, t3, t4;
        t1 = clock();
        a = direct_poly(2);
        t2 = clock();
        meantime1 += t2 - t1;
        usleep(100);
        t3 = clock();
	    b = horner(2);
        t4 = clock();
        meantime2 += t4 - t3;
        usleep(100);
    }
    printf("%d\n", i);
    printf("%lf\n%lf\n", meantime1, meantime2);
    printf("%lf\n", meantime1 / i-1);
    printf("%lf\n", meantime2 / i-1);
    return 0;
}


double direct_poly(double x)
{
    double a[6] = { 0.00125, 0.0626, 0.435, 1.2215, 1.912, 2.196 };
    double rlt = 0;
    double tmp;
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
	double rlt = a[0];
	for (int i = 6; i > 1; i--) {
		rlt = rlt * x + a[7 - i];
	}
	return rlt;
}