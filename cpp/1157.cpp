#include <stdio.h>

char str[1000010];

int main() {
	register int i = -1;
	register unsigned long long n = 0;
	char str[7] = { 0 };
	scanf("%s", str);
	while (str[++i]) {
		n = (n << 4) + str[i] + (('A' <= str[i] && str[i] <= 'F') ? (-'A'+10):(-'0'));
	}
	printf("%d\n", n);
	return 0;
}
