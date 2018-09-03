#include <stdio.h>

char str[110];
int main() {
	register int n, i, r;
	while (~scanf("%d ", &n)) {
		if (!n) break;
		r = 0;
		while (n--) {
			scanf("%[^\n] ", str);
			for (i = r; str[i] && str[i] != ' '; i++);
			r = i;
		}
		printf("%d\n", r+1);
	}
	return 0;
}
