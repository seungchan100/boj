#include <stdio.h>
inline int mstrcmp(char *a, char *b) {
	register int i;
	for (i = 0; a[i] && b[i] && a[i] == b[i]; i++);
	return b[i]-a[i];
}
char *prev;
char str[2][15];
int main() {
	register int t, i = 0, a, m = 0;
	scanf("%d ", &t);
	scanf("%s", str[i]); t--; 
	while (t--) {
		prev = str[i];
		i++; if (i >= 2) i = 0;
		scanf("%s", str[i]);
		a = mstrcmp(prev, str[i]);
		if (!m) m = a;
		if (!(m < 0 && a < 0) && !(m > 0 && a > 0)) {
			m = 0; break;
		}
	}
	printf("%s", m < 0 ? "DECREASING" : m>0 ? "INCREASING" : "NEITHER");
	return 0;
}
