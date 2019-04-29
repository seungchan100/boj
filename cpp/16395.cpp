#include <stdio.h>

int cache[40][40];

int comb(int n, int k) {
	if (cache[n][k]) return cache[n][k];
	if (k == 0) return cache[n][k] = 1;
	if (k == 1) return cache[n][k] = n;
	if (k > (n >> 1)) return cache[n][k] = comb(n, n - k);
	return cache[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}


int main() {
	register int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", comb(n-1, k-1));
	return 0;
}
