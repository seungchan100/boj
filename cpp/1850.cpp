#include <stdio.h>
typedef unsigned long long ll;
inline void swap(ll *a, ll *b) {
	ll t = *a; *a = *b, *b = t;
}
ll gcm(ll a, ll b) {
	ll c;
	while (b) {
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ll a, b;
	scanf("%llu %llu", &a, &b);
	a = gcm(a, b);
	for (b = 0; b < a; b++) putchar('1');
	return 0;
}
