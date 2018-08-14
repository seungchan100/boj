#include <stdio.h>
char buf[5];
inline int mstrlen(char *a) {
	register int i = 0;
	while (a[i]) i++;
	return i;
}
inline int stoi(char *a) {
	register int i = 0, n = 0;
	while (a[i]) {
		n = n * 10 + (a[i] - '0');
		i++;
	}
	return n;
}
int main() {
	register int n, m, i;
	scanf("%s %d", buf, &m);
	int len = mstrlen(buf);
	n = stoi(buf);
	if (m > len*n) m = len*n;
	int max = m / len;
	for (i = 0; i < max; i++) {
		printf("%s", buf);
	}
	buf[m-len*max] = 0;
	printf("%s", buf);
	return 0;
}
