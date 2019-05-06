
#include <stdio.h>

int main() {
	register int t, n, i, sol;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		sol = 0;
		for (i = 5; i <= n; i*=5) {
			sol += n / i;
		}
		printf("%d\n", sol);
	}
	return 0;
}
