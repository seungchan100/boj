#include <stdio.h>

int n, k, arr[110], tmp[110];
int cache[10010];
void msort(int s, int e) {
	if (s >= e) return;
	int m = (s + e) >> 1, i = s, j = m + 1, k = s;
	msort(s, m), msort(m + 1, e);
	while (i <= m && j <= e) {
		if (arr[i] > arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	while(i <= m) tmp[k++] = arr[i++];
	while(j <= e) tmp[k++] = arr[j++];
	for (i = s; i <= e; i++) arr[i] = tmp[i];
}
int dfs(int target) {
	if (cache[target]) return cache[target];
	if (target == 0) return 0;
	register int i, ret = 987654321, t;
	for (i = 0; i < n; i++) {
		if (target - arr[i] < 0) continue;
		t = 1 + dfs(target - arr[i]);
		if (t < ret) ret = t;
	}
	return cache[target] = ret;
}

int main() {
	register int i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	msort(0, n - 1);
	i = dfs(k);
	printf("%d", i == 987654321 ? -1:i);
	return 0;
}
