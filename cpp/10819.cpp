#include <stdio.h>
int arr[10];
inline int abs(int a) {
	return a < 0 ? -a : a;
}
bool used[10];
int n, max;
void select(int a, int pidx, int sum) {
	if (a == n) {
		if (sum > max) max = sum;
		return;
	}
	register int i;
	for (i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			select(a + 1, i, pidx<0?0:sum+abs(arr[pidx]-arr[i]));
			used[i] = false;
		}
	}
}
int main() {
	register int i, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	select(0, -1, 0);
	printf("%d", max);	
	return 0;
}
