#include <stdio.h>

int arr[2010], N;
int cache[2010][2010];

int ispal(int s, int e) {
	if (cache[s][e]) return cache[s][e];
	if (s >= e) return cache[s][e] = 2;
	return cache[s][e] = (arr[s] == arr[e]) ? ispal(s+1, e-1) : 1;
}

int main() {
	register int i, s, e, m;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", arr + i);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &s, &e);
		putchar(ispal(s, e) + '0' - 1);
		putchar('\n');
	}
	return 0;
}
