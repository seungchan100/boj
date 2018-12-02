#include <stdio.h>
int N, L[30], J[30];
int cache[30][110];
inline int MAX(int a, int b) {
	return a > b ? a : b;
}
int query(int n, int remain) {
	if (cache[n][remain]) return cache[n][remain];
	if (n == N) {
		return cache[n][remain] = 0;
	}
	return cache[n][remain] =
		(remain > L[n]) ?
		MAX(query(n + 1, remain - L[n]) + J[n], query(n + 1, remain)) :
		query(n + 1, remain);
}
int main() {
	register int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", L + i);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", J + i);
	}
	printf("%d", query(0, 100));
	
	return 0;
}
