#include "compile_control.h"
#ifdef SUMFAC
#include <stdio.h>

double SumFac(int x);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.10g\n", SumFac(n));
    return 0;
}

/* 你提交的代码将被嵌在这里 */
double prodLog[500] = { 0 };

double getProduct(int x);
double utilSumFac(int x, double acc);

double SumFac(int x) {
    return utilSumFac(x, 0);
}

double getProduct(int x) {

    if (x == 1)
        return 1;
    if (x == 0)
        return 1;

    if (prodLog[x] != 0)
        return prodLog[x];

    prodLog[x] = x * getProduct(x - 1);
    return prodLog[x];
}

double utilSumFac(int x, double acc) {

    if (x == 0)
        return 1 + acc;

    return utilSumFac(x - 1, acc + getProduct(x));
}

#endif