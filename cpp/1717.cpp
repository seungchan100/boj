#include <stdio.h>
int num[1000010];
int n, m;

inline int find(int x) {
	register int a = x;
	while (a != num[a]) a = num[a];
	return num[x] = a;
}

inline void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	num[a] = b;
}

int main() {
	register int c, a, b, aa, bb;
	scanf("%d %d", &n, &m);
	for (c = 1; c <= n; c++) num[c] = c;
	while (m--) {
		scanf("%d %d %d", &c, &a, &b);
		if (c) {
			printf("%s\n", find(a) == find(b)? "YES" : "NO");
		}
		else {
			merge(a, b);
		}
	}
	return 0;
}
