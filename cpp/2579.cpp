#include <stdio.h>

int dp[310], arr[310];

inline int max(int a, int b){
	return a>b?a:b;
}

int getdp(int i){
	if(dp[i]) return dp[i];
	return dp[i] = arr[i] + max(getdp(i-2), arr[i-1]+getdp(i-3));
}

int main(){
	int i,n;
	
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", arr+i);
	}
	dp[0] = arr[0],
	dp[1] = arr[0] + arr[1],
	dp[2] = arr[2] + max(arr[0], arr[1]);
	printf("%d", getdp(n-1));
	return 0;
}
