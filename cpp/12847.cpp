#include <stdio.h>
typedef unsigned long long LL;
int arr[100010], N, M;
int main() {
	register int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", arr + i);
	LL sum = 0, max = 0;
	for (i = 0; i < M; i++) sum += arr[i];
	max = sum;
	for (i = M; i < N; i++) {
		sum = sum - arr[i - M] + arr[i];
		if (max < sum) max = sum;
	}
	printf("%llu", max);
	return 0;
}
