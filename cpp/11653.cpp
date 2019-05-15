#include <stdio.h>

int main() {
	register int i, a;
	scanf("%d", &a);
	if(a == 1){
		return 0;
	}
	for (i = 2; a != 1; ) {
		if (!(a%i)) {
			printf("%d\n", i);
			a /= i;
		}
		else i++;
	}
	return 0;
}
