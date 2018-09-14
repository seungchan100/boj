#include <stdio.h>
int arr[500010], tmp[500010];
void msort(int s, int e) {
	if (s >= e) return;
	int m = (s + e) >> 1, i = s, j = m + 1, k = s;
	msort(s, m), msort(m + 1, e);
	while (i <= m && j <= e) {
		if (arr[i] < arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	while(i<=m) tmp[k++] = arr[i++];
	while(j<=e) tmp[k++] = arr[j++];
	for (i = s; i <= e; i++) arr[i] = tmp[i];
}
bool bisearch(int s, int e, int t) {
	if (s > e) return false;
	int m = (s + e) >> 1;
	if (arr[m] == t) return true;
	else if (arr[m] < t) return bisearch(m+1, e, t);
	else return bisearch(s, m-1, t);
}

int main() {
	register int n, m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	msort(0, n - 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &i);
		printf("%d ", bisearch(0, n - 1, i));
	}
	return 0;
}
