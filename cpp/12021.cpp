#include <stdio.h>
inline double abs(double n) {
	return n < 0 ? -n : n;
}
inline double sqrt(double n) {
	double a = n / 2;
	while (1) {
		double p = a;
		a = (a + n / a) / 2;
		if (abs(a - p) < 1e-7) break;
	}
	return a;
}
int main() {
	register double a, b;
	scanf("%lf %lf", &a, &b);
	a = sqrt(a*b);
	printf("%.3lf %.3lf", a, a);
	return 0;
}
