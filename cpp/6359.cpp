//https://www.acmicpc.net/problem/6359

#include <stdio.h>

int cache[110] = { 0, 1, };
int sol[110] = { 0, 1, };

int numOfDiv(int n) {
	if (cache[n]) return cache[n];
	register int ret = 0, i;
	for (i = 1; i*i < n; i++) {
		if (!(n%i)) ret+=2;
	}
	if (!(n % (i*i))) ret++;
	return cache[n] = ret;
}


int main() {
	register int t, i = 0;
	
	for (i = 1; i <= 100; i++) {
		numOfDiv(i);
	}
	for (i = 2; i <= 100; i++) {
		sol[i] = sol[i-1]+((numOfDiv(i) & 1) ? 1 : 0);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &i);
		printf("%d\n", sol[i]);
	}
	return 0;
}
