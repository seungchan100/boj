#include <stdio.h>

inline int abs(int a) {
	return a < 0 ? -a : a;
}
bool can[10];
int N, M, ans;

inline bool isEnable(int n) {
	if (!n) return can[0];
	while (n) {
		if (!can[n % 10]) return false;
		n /= 10;
	}
	return true;
}
inline int digit(int n) {
	register int i = 1;
	while (n /= 10) i++;
	return i;
}
inline int getUpper() {
	int num = N, ret = 987654321;
	while (1) {
		ret = num - N + digit(num);
		if (isEnable(num)) {
			return ret;
		}
		if (ret >= ans) return 987654321;
		num++;
	}
	return ret;
}
inline int getLower() {
	int num = N, ret = 987654321;
	while (num >= 0) {
		if (isEnable(num)) {
			return ret = N - num + digit(num);
		};
		num--;
	}
	return ret;
}
int main() {
	register int t;
	for (t = 0; t < 10; t++) can[t] = true;
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d", &t);
		can[t] = false;
	}
	ans = abs(N - 100);
	if (ans == 0) {
		printf("0"); return 0;
	}
	if (M != 10) {
		t = getUpper();
		if (t < ans) ans = t;
		t = getLower();
		if (t < ans) ans = t;
	}
	printf("%d", ans);
	return 0;
}
