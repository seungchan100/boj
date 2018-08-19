#include <stdio.h>
int cache[15][15];
int people(int a, int b) {
	if (cache[a][b]) return cache[a][b];
	if (a == 0) return b;
	register int i, r = 0;
	for (i = 1; i <= b; i++) {
		r += people(a - 1, i);
	}
	return cache[a][b] = r;
}
int main() {
	register int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", people(a, b));
	}
	return 0;
}
