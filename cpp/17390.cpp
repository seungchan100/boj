#include <stdio.h>

int arr[300010], psum[300010], tmp[300010], n, q;

void msort(int s, int e){
	if(s>=e) return;
	int m = (s+e)>>1, i = s, j = m+1, k = s;
	msort(s, m);
	msort(m+1, e);
	while(i <= m && j <= e){
		tmp[k++] = (arr[i] < arr[j])? arr[i++]:arr[j++];
	}
	while(i<=m) tmp[k++] = arr[i++];
	while(j<=e) tmp[k++] = arr[j++];
	for(i=s;i<=e;i++) arr[i] = tmp[i];
}

inline void getPsum(){
	register int i;
	for(i=1;i<=n;i++) psum[i] = psum[i-1]+arr[i];
}

int main(){
	register int i, s, e;
	//freopen("test.txt", "r", stdin);
	scanf("%d %d", &n, &q);
	for(i=1;i<=n;i++) scanf("%d", arr+i);
	msort(1, n);
	getPsum();
	while(q--){
		scanf("%d %d", &s, &e);
		printf("%d\n", psum[e]-psum[s-1]);
	}
	return 0;
}
