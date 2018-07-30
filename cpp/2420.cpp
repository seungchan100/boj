#include <stdio.h>

int main() {
	long long  n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld\n", ((n-m)<0)?m-n:n-m);
	return 0;
}
