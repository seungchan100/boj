#include <stdio.h>
int uniq, map[60][60], X, Y;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
inline bool isValid(int x, int y) {
	return x >= 0 && x < X && y >= 0 && y < Y;
}
void spread(int x, int y) {
	map[x][y] = 0;
	register int i, tx, ty;
	for (i = 0; i < 4; i++) {
		tx = x + dx[i], ty = y + dy[i];
		if (isValid(tx, ty) && map[tx][ty] == uniq) {
			spread(tx, ty);
		}
	}
}
inline int sol() {
	register int x, y, r = 0;
	for (x = 0; x < X; x++) {
		for (y = 0; y < Y; y++) {
			if (map[x][y] == uniq) {
				spread(x, y);
				r++;
			}
		}
	}
	return r;
}
int main() {
	register int x, y, t, n;
	scanf("%d", &t);
	while(t--){
		uniq++;
		scanf("%d %d %d", &X, &Y, &n);
		while (n--) {
			scanf("%d %d", &x, &y);
			map[x][y] = uniq;
		}
		printf("%d\n", sol());
	}
	return 0;
}
