#include <stdio.h>

char str[1010];
char stra[1010][1010];
char *ori[1010], *tmp[1010];

inline void mstrcpy(char *d, char *s) {
	register int i;
	for (i = 0; d[i] = s[i]; i++);
	d[i] = 0;
}
inline char mstrcmp(char *a, char *b) {
	register int i;
	for (i = 0; a[i] && b[i] && a[i] == b[i]; i++);
	return a[i] - b[i];
}
void msort(int s, int e) {
	if (s >= e) return;
	register int i = s, m = (s + e) >> 1, j = m+1, k = s;
	msort(s, m), msort(m + 1, e);
	while (i <= m && j <= e) {
		if (mstrcmp(ori[i], ori[j]) < 0) tmp[k++] = ori[i++];
		else tmp[k++] = ori[j++];
	}
	while(i<=m) tmp[k++] = ori[i++];
	while(j<=e) tmp[k++] = ori[j++];
	for (i = s; i <= e; i++) ori[i] = tmp[i];
}

int main() {
	register int i,j;
	scanf("%s", str);
	for (i = 0; str[i]; i++) {
		mstrcpy(stra[i], str+i);
		ori[i] = stra[i];
	}
	msort(0, i - 1);
	for (j = 0; j < i; j++) printf("%s\n", ori[j]);
	return 0;
}
