#include <stdio.h>


int arr[500010], tmp[500010];

void msort(int s, int e) {
	if (s >= e) return;
	register int i = s, m = (s + e) >> 1, j = m + 1, k = s;
	msort( s, m), msort( m + 1, e);
	while (i <= m && j <= e) {
		if (arr[i] > arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	while(i<=m) tmp[k++] = arr[i++];
	while(j<=e) tmp[k++] = arr[j++];
	for (i = s; i <= e; i++) arr[i] = tmp[i];
}

struct MRV {
	int num, cnt;
	MRV() { num = cnt = 0; }
};
MRV mrv[8010], *pmrv[8010], *tmrv[8010];

int mrvcmp(MRV *a, MRV *b) {
	if (a->cnt != b->cnt) return a->cnt - b->cnt;
	return b->num - a->num;
}

void msort2(int s, int e) {
	if (s >= e) return;
	register int i = s, m = (s + e) >> 1, j = m + 1, k = s;
	msort2(s, m), msort2(m + 1, e);
	while (i <= m && j <= e) {
		if (mrvcmp(pmrv[i], pmrv[j]) > 0) tmrv[k++] = pmrv[i++];
		else tmrv[k++] = pmrv[j++];
	}
	while (i <= m) tmrv[k++] = pmrv[i++];
	while (j <= e) tmrv[k++] = pmrv[j++];
	for (i = s; i <= e; i++) pmrv[i] = tmrv[i];
}

int main() {
	int t, i, sum = 0, N, mid;
	scanf("%d", &N);
	for (i = 0; i < 8010; i++) {
		pmrv[i] = &mrv[i];
	}
	for (i = 0; i < N; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
		t = arr[i] + 4000;
		mrv[t].num = arr[i];
		mrv[t].cnt++;
	}
	msort(0, N - 1);
	msort2(0, 8009);
	printf("%1.f \n%d \n%d \n%d", sum / (double)N, arr[N / 2],
		pmrv[0]->cnt == pmrv[1]->cnt ?
		pmrv[1]->num : pmrv[0]->num,
		arr[0] - arr[N - 1]);
	return 0;
}
