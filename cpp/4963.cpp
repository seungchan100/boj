#include <stdio.h>
int W, H, ret;
char map[60][60];
bool visit[60][60];
int dw[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dh[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
inline void init() {
	register int w, h;
	for (h = 0; h < H; h++) {
		for (w = 0; w < W; w++) {
			scanf("%d", &map[h][w]);
			visit[h][w] = false;
		}
	}
	ret = 0;
}

void spread(int h, int w) {
	if (visit[h][w]) return;
	if (w < 0 || w >= W || h < 0 || h >= H || !map[h][w]) return;
	visit[h][w] = true;
	register int i;
	for (i = 0; i < 8; i++) {
		spread(h + dh[i], w + dw[i]);
	}
}
inline void run() {
	register int w, h, r;
	for (h = 0; h < H; h++) {
		for (w = 0; w < W; w++) {
			if (visit[h][w]) continue;
			if (map[h][w]) {
				spread(h, w);
				ret++;
			}
		}
	}
	printf("%d\n", ret);
}
int main() {
	while (1) {
		scanf("%d %d", &W, &H);
		if (!W && !H) break;
		init();
		run();
	}
	return 0;
}
