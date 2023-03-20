#include "compile_control.h"
#ifdef REVERSE
#include <stdio.h>
# include <math.h>

unsigned int reverse(unsigned int number);

int main()
{
    unsigned int n;

    scanf("%u", &n);
    printf("%u\n", reverse(n));

    return 0;
}


/* 请在这里填写答案 */
unsigned int reverse(unsigned int number) {

    if (number < 10)
        return number;

    int counter = 0;
    unsigned int copy = number;
    while (copy > 0) {
        copy /= 10;
        counter++;
    }

    return (number % 10) * pow(10, counter - 1) + reverse(number / 10);

}

#endif