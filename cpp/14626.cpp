#include <stdio.h>
char str[15];
int main() {
	register int i, sum = 0, j;
	scanf("%s", str);
	for (i = 0; str[i]; i++) {
		if (str[i] != '*') {
			sum += (i & 1 ? 3 : 1)*(str[i] - '0');
		}
		else j = i;
	}
	sum %= 10;
	j = (j & 1 ? 3 : 1);
	for (i = 0; i <= 9; i++) {
		if (!((sum + i*j) % 10)) break;
	}
	printf("%d", i);
	return 0;
};
