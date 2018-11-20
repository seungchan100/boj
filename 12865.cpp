#include <stdio.h>

inline int MAX(int a, int b) {
	return a > b ? a : b;
}
int cache[110][100010];
int W[110], V[110], N, K;
int ans(int n, int k) {
	if (cache[n][k]) return cache[n][k];
	if (!n) return cache[n][k] = k >= W[0] ? V[0] : 0;
	return cache[n][k] = k >= W[n] ?
		MAX(ans(n - 1, k), ans(n - 1, k - W[n]) + V[n]) :
		ans(n - 1, k);
}

int main() {
	register int i;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d %d", W + i, V + i);
	}
	printf("%d", ans(N - 1, K));
	return 0;
}
