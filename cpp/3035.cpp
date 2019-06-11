#include <stdio.h>

char map[60][60];
char zmap[260][260];

int main() {
	register int i, j, r, c, zr, zc, zrr, zcc;
	scanf("%d %d %d %d", &r, &c, &zr, &zc);
	for (i = 0; i < r; i++) scanf(" %s ", map[i]);
	zrr = r*zr, zcc = c*zc;
	for (i = 0; i < zrr; i++) {
		for (j = 0; j < zcc; j++) {
			zmap[i][j] = map[i / zr][j / zc];
		}
	}
	
	for (i = 0; i < zrr; i++) printf("%s\n", zmap[i]);
	return 0;
}
