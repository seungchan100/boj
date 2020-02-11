#include <stdio.h>

int N, M, L, cnt=-1;
int arr[1010];

int main(void) {
//	freopen("test.txt","r",stdin);
	scanf("%d %d %d", &N, &M, &L);
	for(register int i=0;;){
		arr[i]++;
		cnt++;
//		printf("%d %d\n", i, arr[i]);
		if(arr[i] == M) break;
		if(arr[i]&1){
			i = (i+L)%N;
		}else{
			i = i-L;
			if(i<0) i = N+i%N;
		}
	}
	printf("%d", cnt);
	return 0;
}
