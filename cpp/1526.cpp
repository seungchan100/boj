#include <stdio.h>

int solve() {
	int n, i, sol = 0;
	scanf("%d", &n);
	for (i = 1;; i *= 10) {
		sol += (i << 2);
		if (sol == n) return sol;
		if (sol > n) {
			sol /= 10;
			break;
		}
		
	}

	for (i /= 10 ; i > 0; i /= 10) {
		sol += 3*i;
		if (sol == n) return sol;
		if (sol > n) sol -= 3 * i;
	}
	return sol;
}

int main() {
	printf("%d", solve());
	return 0;
}
