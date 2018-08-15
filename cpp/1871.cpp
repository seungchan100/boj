#include <stdio.h>
char buf[5];
inline int sti(char *a) {
	register int i = 0, ret = 0;
	while (a[i]) {
		ret = ret * 26 + a[i] - 'A';
		i++;
	}
	return ret;
}
inline int abs(int a) {
	return a < 0 ? -a : a;
}
int main() {
	register int b, i,t;
	scanf("%d", &t);
	while (t--) {
		scanf("%3s-%d", buf, &b);
		printf("%snice\n", abs(b - sti(buf)) <= 100 ? "" : "not ");
	}
	return 0;
}
