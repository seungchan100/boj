#include <stdio.h>
char cmd[10];
int main() {
	register int t, n, s = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%s %d", cmd, &n);
		switch (cmd[0]) {
		case 'a':
			if (cmd[1] == 'd') {
				s |= 1 << n;
			}
			else if (cmd[1] == 'l') {
				s = 0xffffffff;
			}
			break;
		case 'r':
			s &= ~(1 << n);
			break;
		case 'c':
			printf("%d\n", !!(s & (1 << n)));
			break;
		case 't':
			s ^= (1 << n);
			break;
		case 'e':
			s = 0;
			break;
		}
	}
	return 0;
}
