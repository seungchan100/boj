#include <stdio.h>


int main() {
	int k, n, t, limit = 210;
	char z;
	scanf("%d %d", &k, &n);
	while (n--) {
		scanf(" %d %c ", &t, &z);
		limit -= t;
		if (limit < 0) {
			printf("%d", k);
			return 0;
		}
		if (z == 'T') {
			k++;
			if(k>8) k = 1;
		}
	}
	return 0;
}
