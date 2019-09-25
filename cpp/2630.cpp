//	https://www.acmicpc.net/problem/2630

#include <stdio.h>

int map[130][130];
int cnt[2];

inline bool isAllSame(int color, int r, int c, int size) {
	register int rr, cc, rmax = r+size, cmax  = c+size;
	for (rr = r; rr < rmax; rr++) {
		for (cc = c; cc < cmax; cc++) {
			if (color != map[rr][cc]) return false;
		}
	}
	return true;
}


void dnq(int r, int c, int size) {
	if (size == 1 || isAllSame(map[r][c], r, c, size)) {
		cnt[map[r][c]]++;
		return;
	}
	size >>= 1;
	dnq(r, c, size);
	dnq(r + size, c, size);
	dnq(r, c + size, size);
	dnq(r + size, c + size, size);
}


int main() {
	int size, r, c;
	scanf("%d", &size);
	for (r = 0; r < size; r++) {
		for (c = 0; c < size; c++) {
			scanf("%d", &map[r][c]);
		}
	}
	dnq(0, 0, size);
	printf("%d\n%d", cnt[0], cnt[1]);
	return 0;
}
