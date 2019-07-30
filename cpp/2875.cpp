#include <stdio.h>

int main() {
	int n, m, k, team, remain;
	scanf("%d %d %d", &n, &m, &k);
	if ((n >> 1) >= m) {
		team = m;
		remain = n - (team << 1);
	}
	else {
		team = n >> 1;
		remain = m - team;
	}
	if (remain < k) {
		k -= remain;
		while (k > 0) {
			team--;
			k -= 3;
		}
	}
	printf("%d", team);
	return 0;
}
