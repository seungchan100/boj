#include <stdio.h>

int t[20];
int p[20];
int n;
int cache[20][20];

inline int max(int a, int b){
	return a>b?a:b;
}

int solve(int s, int e){
	if(cache[s][e]) return cache[s][e];
	if(s >= e) return 0;
	if(s+t[s] > e) return solve(s+1, e);
	return cache[s][e] = max(p[s]+solve(s+t[s], e), solve(s+1, e));
}

int main() {
	int i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &t[i], &p[i]);
	}
	printf("%d\n", solve(0, n));
	return 0;
}
