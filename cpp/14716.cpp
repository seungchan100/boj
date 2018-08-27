#include <stdio.h>
char map[300][300];
bool visit[300][300];
int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int R, C;
void sweep(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C || visit[r][c]) return;
	visit[r][c] = true;
	if (map[r][c] == 1) {
		register int i;
		map[r][c] = 2;
		for (i = 0; i < 8; i++) sweep(r + dr[i], c + dc[i]);
	}
}
int main() {
	register int r, c, ret = 0;
	scanf("%d %d", &R, &C);
	for (r = 0; r < R; r++) for (c = 0; c < C; c++)scanf("%d", &map[r][c]);
	for (r = 0; r < R; r++) {
		for (c = 0; c < C; c++) {
			if (map[r][c] == 1) {
				ret++; sweep(r, c);
			}
		}
	}
	printf("%d", ret);
	return 0;
}
