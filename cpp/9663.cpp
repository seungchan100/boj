#include <stdio.h>

int n, ret;
bool map[20][20];
inline bool valid(int r, int c) {
	register int i;
	for (i = 0; i < r; i++) {
		if (map[i][c]) return false;
		if (c - (r - i) >=0 && map[i][c - (r - i)]) return false;
		if (c + (r - i) < n && map[i][c + (r - i)]) return false;
	}
	return true;
}
void dfs(int r) {
	if (r == n) {
		ret++; return;
	}
	register int c;
	for (c = 0; c < n; c++) {
		if (valid(r, c)) {
			map[r][c] = true;
			dfs(r + 1);
			map[r][c] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	dfs(0);
	printf("%d", ret);
	return 0;
}
