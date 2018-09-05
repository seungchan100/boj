#include <stdio.h>

char str[110];
inline int mstrlen(char *a) {
	register int i;
	for (i = 0; str[i]; i++);
	return i;
}
char a[] = "aeiou";
bool isA(char c) {
	for (register int i = 0; i < 5; i++) {
		if (c == a[i]) return true;
	}
	return false;
}
int main() {
	register int t, i, j;
	while (1) {
		scanf("%s", str);
		if (str[0] == '#') break;
		int len = mstrlen(str);
		j = len;
		for (i = 0; str[i] && i<len; i++) {
			if (isA(str[i])) break;
			else {
				str[j++] = str[i];
			}
		}
		printf("%say\n", str+i);
		for (i = 0; str[i]; i++) str[i] = 0;
	}
	return 0;
}
