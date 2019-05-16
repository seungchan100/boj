#include <stdio.h>

int main() {
	register int i, n, sol = 0, d = 1;
	scanf("%d", &n);
	for (i = 1; ; i *= 10, d++) {
		if (n >= (i*10)) {
			sol += d * 9 * i;
		}
		else {
			sol += d * (n-(i-1));
			break;
		}
	}
	printf("%d", sol);
	return 0;
}
