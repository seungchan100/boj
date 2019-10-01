#include <stdio.h>

inline bool isCycle(int start, int *arr,bool *visit){
	for(int n = arr[start];;n = arr[n]){
		if(n == start){
			visit[n] = true;
			return true;
		} 
		if(visit[n]){
			return false;
		} 
		visit[n] = true;
	}
	return false;
}

int test(){
	int arr[1010]= {0,};
	bool visit[1010] = {0,};
	int i, n, sol = 0;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%d", arr+i);
	}
	for(i=1;i<=n;i++){
		if(visit[i]) continue;
		if(isCycle(i, arr, visit)) sol++;
	}
	printf("%d\n", sol);
	return 1;
}


int main(void) {
//	freopen("test.txt", "r", stdin); 
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
