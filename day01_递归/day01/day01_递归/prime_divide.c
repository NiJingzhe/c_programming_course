#include "compile_control.h"

#ifdef prime_divide

#include <stdio.h>
#include <math.h>

#define LENGTH (100000+5)



int times[LENGTH] = { 0 };

void saparate(int n);
int check_prime(int n);
long long int qpow(int x, int n);

int main() {
	int n;
	int first = 1;
	scanf_s("%d", &n);
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	saparate(n);
	printf("%d=", n);
	for (int i = 0; i < LENGTH; i++) {
		if (times[i] == 1) {
			if (first) { 
				printf("%d", i); 
				first = 0; 
			}
			else printf("*%d", i);
		}
		if (times[i] >= 2) {
			if (first) {
				printf("%d^%d", i, times[i]); 
				first = 0;
			}
			else printf("*%d^%d", i, times[i]);
		}
	}
	return 0;
}

long long int qpow(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n % 2 == 1)
		return x * qpow(x, n - 1);
	if (n % 2 == 0) {
		long long int temp = qpow(x, n / 2);
		return temp * temp;
	}
}

int check_prime(int n) {
	for (int i = 2; qpow(i, 2) <= n; i++)
		if (n % i == 0) return 0;

	return 1;
}

void saparate(int n) {
	for (int i = 2; i <= n; i++) {
		if (n % i == 0 && check_prime(i)) {
			while (n % i == 0) {
				n /= i;
				times[i]++;
			}
		}
	}
	return;
}

#endif