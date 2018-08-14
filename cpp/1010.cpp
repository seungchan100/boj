#include <stdio.h>

int cache[40][40];
int com(int n, int k) {
	if (k > n / 2) k = n - k;
	if (k == 0) return 1;
	if (k == 1) return n;
	if (cache[n][k]) return cache[n][k];
	return cache[n][k] = com(n - 1, k) + com(n - 1, k - 1);
}
int main() {
	register int i, n, k;
	scanf("%d", &i);
	while (i--) {
		scanf("%d %d", &k, &n);
		printf("%d\n", com(n, k));
	}
	return 0;
}
