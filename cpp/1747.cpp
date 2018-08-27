#include <stdio.h>

inline bool isPrime(int a) {
	if (a == 1) return false;
	else if (a == 2) return true;
	for (register int i = 2; i*i <= a; i++) {
		if (!(a%i)) return false;
	}
	return true;
}
inline bool isPal(int a) {
	register int cmp = 0, c = a;
	while (c) {
		cmp = cmp * 10 + c % 10;
		c /= 10;
	}
	return a == cmp;
}

int main() {
	int n;
	scanf("%d", &n);
	while (1) {
		if (isPal(n) && isPrime(n)) {
			printf("%d\n", n);
			break;
		}
		n++;
	}
	return 0;
}
