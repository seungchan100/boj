#include <stdio.h>
inline bool inner(int a, int b, int x, int y, int r) {
	return (a - x)*(a - x) + (b - y)*(b - y) < r*r;
}
inline bool outer(int a, int b, int x, int y, int r) {
	return (a - x)*(a - x) + (b - y)*(b - y) > r*r;
}
int main() {
	register int t, x[2], y[2], r, i, n, ret, xx, yy, rr;
	scanf("%d", &t);
	while (t--) {
		ret = 0;
		for (i = 0; i < 2; i++) {
			scanf("%d %d", x+i, y+i);
		}
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &xx, &yy, &rr);
			if (inner(x[0], y[0], xx, yy, rr) && outer(x[1], y[1], xx, yy, rr)) ret++;
			if (inner(x[1], y[1], xx, yy, rr) && outer(x[0], y[0], xx, yy, rr)) ret++;
		}
		printf("%d\n", ret);
	}
	
	return 0;
}
