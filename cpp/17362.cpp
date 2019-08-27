#include <stdio.h>

typedef long long ll;

int main() {
	ll a;
	int sol;
	scanf("%lld", &a);
	switch (sol = a % 8) {
	case 0:sol = 2; break;
	case 6:sol = 4; break;
	case 7: sol = 3; break;
	}
	printf("%d", sol);
	return 0;
}
