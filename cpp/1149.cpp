#include <stdio.h>


int cache[1010][3];
int cost[1010][3];


inline int min(int a, int b) {
	return a < b ? a : b;
}

inline int mint(int a, int b, int c) {
	return min(min(a, b), c);
}

int F(int i, int color) {
	if (cache[i][color])
		return cache[i][color];
	if (i == 0)
		return cache[i][color] = cost[i][color];
	return cache[i][color] = min(
		cost[i][color] + F(i - 1, (color + 1) % 3), 
		cost[i][color] + F(i - 1, (color + 2) % 3)
	);
}


int main() {
	register int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	printf("%d", mint(F(n - 1, 0), F(n - 1, 1), F(n - 1, 2)));
	return 0;
}
