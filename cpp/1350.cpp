#include <stdio.h>

typedef long long ll;

ll arr[1010];

int main() {
	register int i, n, size;
	ll sol = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", arr + i);
	scanf("%d", &size);
	for (i = 0; i < n; i++) {
		sol += (arr[i]/size)*size + (arr[i]%size?size:0);
	}
	printf("%lld", sol);
	return 0;
}
