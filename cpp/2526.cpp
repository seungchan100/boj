#include <stdio.h>

int cache[1000010];
int main() {
	register int i = 1, n, p, nn;
	scanf("%d %d", &n, &p);
	cache[n] = 1;
	nn = n;
	while (1) {
		nn = nn*n%p;
		if (cache[nn]) break;
		cache[nn] = ++i;
	}
	printf("%d", i - cache[nn]+1);
	return 0;
}
