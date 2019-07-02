#include <stdio.h>


int arr[8];
int marr[8];
int N;
int cache[10010];

void msort(int s, int e) {
	if (s >= e) return;
	int i = s, m = (s + e) >> 1, j = m+1, k = s;
	msort(s, m);
	msort(m+1, e);
	while (i <= m && j <= e) {
		if (arr[i] < arr[j]) marr[k++] = arr[i++];
		else marr[k++] = arr[j++];
	}
	while(i<=m)  marr[k++] = arr[i++];
	while(j<=e) marr[k++] = arr[j++];
	for (i = s; i <= e; i++) {
		arr[i] = marr[i];
	}
}

void dfs(int c, int e, int *sol) {
	register int i;
	if (c == e) {
		for (i = 0; i < e; i++) {
			printf("%d ", sol[i]);
		}
		printf("\n");
		return;
	}
	for (i = 0; i < N; i++) {
		sol[c] = arr[i];
		dfs(c + 1, e, sol);
	}
}

int main() {
	register int n, m, i, num, sol[8];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		if (!cache[num]) {
			cache[num] = 1;
			arr[N++] = num;
		}
	}
	msort(0, N-1);
	dfs(0, m, sol);
	return 0;
}
