#include <stdio.h>
#define WPOWER 0
#define BPOWER 1
int R, C, power[2];
char map[110][110];
bool check[110][110];
int dr[] = { 0, 0, 1, -1 },
	dc[] = { -1, 1, 0, 0 };
inline bool valid(int r, int c) {
	return r >= 0 && c >= 0 && r < R && c < C && !check[r][c];
}
int spread(int r, int c, char ch) {
	if (check[r][c]) return 0;
	register int i, nr, nc, ret = 1;
	check[r][c] = true;
	for (i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (valid(nr, nc) && map[nr][nc] == ch) {
			ret += spread(nr, nc, ch);
		}
	}
	return ret;
}

inline int square(int a) {
	return a*a;
}
int main() {
	register int r, c;
	scanf("%d %d", &C, &R);
	for (r = 0; r < R; r++) {
		scanf(" %s ", map[r]);
	}
	for (r = 0; r < R; r++) {
		for (c = 0; c < C; c++) {
			power[map[r][c] == 'W'?WPOWER: BPOWER]
				+= square(spread(r, c, map[r][c]));
		}
	}
	printf("%d %d", power[WPOWER], power[BPOWER]);
	return 0;
}
