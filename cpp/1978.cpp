#include <stdio.h>
inline bool isPrime(int n) {
	switch (n) {
	case 1:return false;
	case 2: 
	case 3:
		return true;
	}
	register int i;
	for (i = 2; i*i <= n; i++) {
		if (!(n%i)) return false;
	}
	return true;
}
bool p[1001];
int main() {
	register int i, t, ret = 0;
	for (i = 1; i <= 1000; i++) p[i] = isPrime(i);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &i);
		if (p[i]) ret++;
	}
	printf("%d", ret);
	return 0;
}
