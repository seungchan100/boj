#include <stdio.h>
int M, N, map[1010][1010], rest, r, c, fr, re;
bool visit[1010][1010];
struct Data {
	int r, c, t;
} queue[1000020];

inline bool isValid(int r, int c) {
	return r >= 0 && c >= 0 && r<N && c<M && !visit[r][c];
}
inline void eq(int nr, int nc, int nt) {
	if (!isValid(nr, nc)) return;
	visit[nr][nc] = true;
	if(!map[nr][nc]) rest--;
	queue[re++] = { nr, nc, nt };
}
inline Data *dq() {
	return &queue[fr++];
}
inline bool empty() {
	return fr == re;
}
int dr[] = { 0, 0, 1, -1 },
dc[] = { 1, -1, 0, 0 };

int main() {
	scanf("%d %d", &M, &N);
	for (r = 0; r < N; r++) {
		for (c = 0; c < M; c++) {
			scanf("%d", &map[r][c]);
			if (map[r][c] == 1) eq(r, c, 0);
			else if (map[r][c] == 0) rest++;
			else if (map[r][c] == -1) visit[r][c] = true;
		}
	}
	Data *dt;
	while (!empty()) {
		dt = dq();
		for (r = 0; r < 4; r++) {
			eq(dt->r + dr[r], dt->c + dc[r], dt->t + 1);
		}
	}
	printf("%d", rest ? -1 : dt->t);
	return 0;
}
