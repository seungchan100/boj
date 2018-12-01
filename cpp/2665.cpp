#include <stdio.h>

char map[60][60];
int N;
int cost[60][60];

struct Data {
	int r, c, t;
	Data() {
		r = c = t = 0;
	}
	Data(int nr, int nc, int nt) {
		r = nr, c = nc, t = nt;
	}
};

Data queue[250000];
int fr, re;
inline void eq(int r, int c, int t) {
	queue[re] = { r, c, t };
	re++;
}
inline Data *dq() {
	return &queue[fr++];
}
inline bool empty() {
	return fr == re;
}

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

inline bool valid(int r, int c) {
	return r >= 0 && c >= 0 && r < N && c < N;
}
int main() {
	register int r, c, nr, nc, i, nt;
	scanf("%d", &N);
	for (r = 0; r < N; r++) {
		scanf(" %s ", map[r]);
	}
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			cost[r][c] = 987654321;
		}
	}
	cost[0][0] = 0;
	eq(0, 0, 0);
	
	while (!empty()) {
		Data *data = dq();
		for (i = 0; i < 4; i++) {
			nr = data->r + dr[i];
			nc = data->c + dc[i];
			if (valid(nr, nc)) {
				nt = map[nr][nc] == '1' ? data->t : data->t + 1;
				if (cost[nr][nc] <= nt) continue;
				cost[nr][nc] = nt;
				eq(nr, nc, nt);
			}
		}
	}
	printf("%d", cost[N - 1][N - 1]);
	return 0;
}
