#include <stdio.h>

int arr[10], tmp[10], sol[10], N, M;

void msort(int s, int e){
	int m=(s+e)>>1, i=s, j=m+1, k = s;
	if(s>=e) return;
	msort(s, m);
	msort(j, e);
	while(i <= m && j <= e){
		tmp[k++] = (arr[i] < arr[j])? arr[i++]:arr[j++];
	}
	while(i<=m) tmp[k++] = arr[i++];
	while(j<=e) tmp[k++] = arr[j++];
	for(i=s;i<=e;i++){
		arr[i] = tmp[i];
	}
}


inline void printSol(){
	register int i;
	for(i=0;i<M;i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}

void solve(int cidx, int cloc){
	int i;
	if(cloc == M){
		printSol();
		return;
	}
	for(i=cidx;i<N;i++){
		sol[cloc] = arr[i];
		solve(i+1, cloc+1);
	}
}

int main() {
	int i;
//	freopen("test.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++){
		scanf("%d", arr+i);
	}
	msort(0, N-1);
	solve(0, 0);
	return 0;
}
