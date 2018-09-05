#include <stdio.h>

char str[10];
int t10(char *s, int d) {
	register int i, r = 0;
	for (i = 0; s[i]; i++) {
		r = r * d + s[i] + (s[i] <= '9' ? -'0' : -'a' + 10);
	}
	return r;
}
int main() {
	scanf("%s", str);
	printf("%d",
		str[1] == 'x' ? t10(str + 2, 16) :
		str[0] == '0' ? t10(str + 1, 8) :
		t10(str, 10));

	return 0;
}
