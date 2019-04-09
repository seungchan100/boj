#include <stdio.h>

int main() {
	register int e, s, m, k = 1 ;
	scanf("%d %d %d", &e, &s, &m);
	while ((((k-1)%15 + 1) != e) || (((k-1)%28 + 1)!= s) || (((k-1)%19 + 1) != m)) k++;
	printf("%d", k);
	return 0;
}
