#include <stdio.h>
int main() {
	register int a[3], b[3], i;
	for (i = 0; i < 3; i++) scanf("%d %d", &a[i], &b[i]);
	printf("%d %d", a[0]^a[1]^a[2], b[0]^b[1]^b[2]);
	return 0;
}
