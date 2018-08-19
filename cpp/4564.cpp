#include <stdio.h>
inline int mul(int n) {
	register int r = 1;
	while (n) {
		r *= n % 10;
		n /= 10;
	}
	return r;
}
int main() {
	register int n, r;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		while (1) {
			printf("%d ", n);
			if (!(n / 10)) break;
			n = mul(n);
		}
		printf("\n");
	}
	return 0;
}
