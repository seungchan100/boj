#include <stdio.h>
int num[20000010];
int n, m;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		num[m + 10000000]++;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		printf("%d ", num[n + 10000000]);
	}

	return 0;
}
