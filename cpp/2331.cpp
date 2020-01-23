#include <stdio.h>
#define MAX 250000

int next[MAX];
int num[MAX];
int mul[10][10];
int N, P;


int getNext(int a){
	int r = 0, t = 0;
	if(next[a]) return next[a];
	for(;a;a/=10){
		t += mul[a%10][P];
	}
	
	return t;
}

inline void getMul(){
	int i, j, t;
	for(i=1;i<10;i++){
		for(j=1, t=i;j<=5;j++,t*=i){
			mul[i][j] = t;
			//printf("%d %d %d\n", i, j, t);
		}
		
	}
}

int main(){
	int i, r = 0;
	getMul();
	freopen("test.txt", "r", stdin);
	scanf("%d %d", &N, &P);
	
	while(num[N] != 3){
		num[N]++;
		N = getNext(N);
	}
	for(i=0;i<MAX;i++){
		if(num[i] == 1) r++;
	}
	printf("%d", r);
	
	return 0;
}
