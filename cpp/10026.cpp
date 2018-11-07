#include <stdio.h>
char mapa[110][110], mapb[110][110];
int N;

int acnt, bcnt;
int dr[] = { 1, 0, -1, 0 },
	dc[] = { 0, 1, 0, -1 };

inline bool valid(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}

void spread(int r, int c, char ch, bool isFirst, char map[][110]){
	if (isFirst) map == mapa ? acnt++ : bcnt++;
	register int i, nr, nc;
	map[r][c] = 0;
	for (i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (valid(nr, nc) && ch == map[nr][nc]) {
			spread(nr, nc, ch, false, map);
		}
	}
}


int main() {
	register int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf(" %s", mapa[i]);
		for (j = 0; j < N; j++) {
			mapb[i][j] = mapa[i][j] == 'R' ? 'G' : mapa[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if(mapa[i][j])
				spread(i, j, mapa[i][j], true, mapa);
			if(mapb[i][j])
				spread(i, j, mapb[i][j], true, mapb);
		}
	}
	printf("%d %d", acnt, bcnt);
	return 0;
}
