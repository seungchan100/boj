#include <stdio.h>
int n, sum;
int map[110][110];
bool used[10010];
bool ismagic = true;
inline bool isMagic() {
	if (!ismagic) return false;
	register int r, c, s1, s2;
	for (r = 0; r < n; r++) {
		s1 = s2 = 0;
		for (c = 0; c < n; c++) {
			s1 += map[r][c];
			s2 += map[c][r];
		}
		if (sum != s1 || sum != s2) {
			return false;
		}
	}
	s1 = s2 = 0;
	for (r = 0; r < n; r++) {
		s1 += map[r][r];
		s2 += map[r][n - r-1];
	}
	if (sum != s1 || sum != s2) {
		return false;
	}
	return true;
}

inline void init() {
	register int r, c;
	scanf("%d", &n);
	sum = (n*(n*n + 1)) >> 1;
	for (r = 0; r < n; r++) {
		for (c = 0; c < n; c++) {
			scanf("%d", &map[r][c]);
			used[map[r][c]] = true;
		}
	}
}


int main() {
	init();
	register int r;
	for (r = 1; r <= n; r++) {
		if (!used[r]) {
			ismagic = false;
			break;
		}
	}
	printf("%s", isMagic()?"TRUE":"FALSE");
	return 0;
}
