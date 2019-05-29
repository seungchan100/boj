#include <stdio.h>

int cache[3010][3010];

int comb(int a, int b) {
	if (cache[a][b]) return cache[a][b];
	if (b == 0) return cache[a][b] = 1;
	if (b == 1) return cache[a][b] = a;
	if ((a >> 1) < b) return comb(a, a-b);
	return cache[a][b] = comb(a - 1, b) + comb(a - 1, b - 1);
}

int main() {
	register int n;
	scanf("%d", &n);
	printf("%d", comb(n / 3 - 1, 2));
	return 0;
}
