#include <stdio.h>

#define MAX 123456*2
int isPrimeCache[300000] = {-1, };
int primeCnt[300000];

inline int isPrime(int n){
	register int i;
	if(isPrimeCache[n] != 0) return isPrimeCache[n];
	for(i=2;i*i<=n;i++){
		if(!(n%i)) return isPrimeCache[n] = -1;
	}
	return isPrimeCache[n] = 1;
}

int main(void) {
	register int i, j, n;
//	freopen("test.txt","r",stdin);
	for(i=2;i<=MAX;i++){
		if(isPrime(i)){
			for(n = i<<1;n<=249912; n += i){
				isPrimeCache[n] = -1;
			}
		}
		
	}
	
	for(i=2;i<=MAX;i++){
		primeCnt[i] = primeCnt[i-1] + (isPrime(i)==1?1:0);
	}
	
	for(;scanf("%d", &i)&&i;){
		printf("%d\n", primeCnt[i<<1]-primeCnt[i]);
	}
	
	return 0;
}
