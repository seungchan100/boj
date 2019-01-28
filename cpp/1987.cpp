#include <stdio.h>

int R, C, max;
int dr[] = { 0, 0, 1, -1 },
dc[] = { 1, -1, 0, 0 };
char map[25][25];
inline bool valid(int r, int c, bool al[26]) {
	return r >= 0 && c >= 0 && r < R && c < C && !al[map[r][c]-'A'];
}
void dfs(int t, int r, int c, bool al[26]) {
	register int i;
	if (max < t) max = t;
	for (i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (valid(nr, nc, al)) {
			al[map[nr][nc] - 'A'] = true;
			dfs(t + 1, nr, nc, al);
			al[map[nr][nc] - 'A'] = false;
		}
	}
}

int main() {
	register int r, c;
	scanf("%d %d", &R, &C);
	for (r = 0; r < R; r++) scanf(" %s ", map[r]);
	bool al[26] = { 0, };
	al[map[0][0] - 'A'] = true;
	dfs(1, 0, 0, al);	
	printf("%d", max);
	return 0;
}
