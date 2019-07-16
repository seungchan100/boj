#include <stdio.h>
int main() {
	int i,n;
	scanf("%d", &i);
	while (i--) {
		scanf("%d", &n);
		printf("%d\n", ((n - 1) & n)?0:1);
	}
	return 0;
}
