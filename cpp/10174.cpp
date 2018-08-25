#include <stdio.h>
char str[110];
inline int mstrlen(char *a) {
	register int i = 0;
	while (a[i]) i++;
	return i;
}
inline bool isPal(char *a) {
	register int i, len = mstrlen(str), max = len >> 1;
	for (i = 0; i <= max; i++) {
		if ('a' <= a[i] && a[i] <= 'z') a[i] -= 'a' - 'A';
		if ('a' <= a[len - i - 1] && a[len - i - 1] <= 'z') a[len - i - 1] -= 'a' - 'A';
		if (a[i] != a[len - i - 1]) return false;
	}
	return true;
}
int main() {
	register int t, i;
	scanf("%d ", &t);
	while (t--) {
		scanf("%[^\n] ", str);
		printf("%s\n", isPal(str) ? "Yes" : "No");
	}
	return 0;
}
