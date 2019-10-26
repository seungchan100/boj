#include <stdio.h>

int n, m, arr[10];
bool flag[10];

inline void printArr(){
	int i;
	for(i=0;i<m;i++) printf("%d ", arr[i]);
	printf("\n");
}

void dfs(int ci){
	int i;
	if(ci == m){
		printArr();
		return;
	}
	for(i=1;i<=n;i++){
		if(!flag[i]){
			flag[i] = true;
			arr[ci] = i;
			dfs(ci+1);
			flag[i] = false;
		}
	}
}


int main(void) {
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}
