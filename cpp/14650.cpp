#include <stdio.h>

int solve(int c, int e, int sum) {
	register int i, sol = 0;
	if (c == e)
		return sum % 3 ? 0 : 1;
	for (i = 0; i < 3; i++) {
		if (!c && !i) continue;
		sol += solve(c + 1, e, sum * 10 + i);
	}
	return sol;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solve(0, n, 0));
	return 0;
}
