#include <stdio.h>

int main() {
	register int i, n, b[110];
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	printf("%d ", b[1]);
	for (i = 2; i <= n; i++) {
		printf("%d ", i*b[i]-(i-1)*b[i-1]);
	}
	return 0;
}
