#include <stdio.h>
char a[110], b[110];
inline int mstrlen(char *a) {
	register int i = 0;
	while (a[i])i++;
	return i;
}
int main() {
	register int t, i;
	char op;
	scanf("%s %c %s", a, &op, b);
	if (op == '*') {
		printf("%s%s", a, b + 1);
	}
	else {
		int alen = mstrlen(a), blen = mstrlen(b);
		if (alen == blen) {
			a[0] = '2'; printf("%s", a);
		}
		else if (alen > blen) {
			a[alen - blen] = '1'; printf("%s", a);
		}
		else {
			b[blen - alen] = '1'; printf("%s", b);
		}
		
	}
	return 0;
}
