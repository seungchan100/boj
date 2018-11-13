#include <stdio.h>

int arr[1000010], tmp[1000010];

inline void msort(int s, int e) {
	if (s >= e) return;
	register int i = s, m = (s + e) >> 1, j = m + 1, k = s;
	msort(s, m), msort(m + 1, e);
	while (i <= m && j <= e) {
		if (arr[i] < arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	while(i<=m) tmp[k++] = arr[i++];
	while(j<=e) tmp[k++] = arr[j++];
	for (i = s; i <= e; i++) arr[i] = tmp[i];
}

inline bool exist(int n, int s, int e) {
	register int m;
	while (s<=e) {
		m = (s + e) >> 1;
		if (arr[m] < n) s = m + 1;
		else if (arr[m] > n) e = m - 1;
		else return true;
	}
	return false;
}

int main() {
	register int i, n, m, t, num;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		msort(0, n - 1);
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &num);
			putchar(exist(num, 0, n-1) ? '1' : '0');
			putchar('\n');
		}
	}
	return 0;
}
