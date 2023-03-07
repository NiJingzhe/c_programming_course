#include "compile_control.h"

#ifdef adder_divide

#include <stdio.h>
#include <math.h>

#include<stdio.h>
int a[100], n;
void divisionInteger(int k, int max, int t);

int main(void) {
	scanf_s("%d", &n);
	divisionInteger(n, n - 1, 0);
	return 0;
}

void divisionInteger(int k, int max, int t) {
	int i, j;

	for (i = max; i > 0; i--) {
		if (k - i == 0) {
			a[t] = i;
			printf("%d=", n);

			for (j = 0; j < t; j++)
				printf("%d+", a[j]);

			printf("%d\n", a[t]);
		}
		else if (k - i > 0) {
			a[t] = i;
			divisionInteger(k - i, i, t + 1);
		}
	}
}


#endif