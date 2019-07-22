#include <stdio.h>

inline int strlen(char *str) {
	register int i;
	for (i = 0; str[i]; i++);
	return i;
}

inline bool isPal(char *str) {
	int len = strlen(str);
	register int i;
	int max = len >> 1;
	for (i = 0; i < max; i++) {
		if (str[i] != str[len - i - 1]) return false;
	}
	return true;
}

int main() {
	char str[10];
	while (scanf(" %s ", str) && str[0] != '0') {
		printf("%s\n", isPal(str)?"yes":"no");
	}
	return 0;
}
