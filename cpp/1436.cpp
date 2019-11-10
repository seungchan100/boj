#include <stdio.h>

inline bool valid666(int a){
	int cnt6 = 0, b;
	for(b=a%10;a;a/=10, b=a%10){
		if(b == 6){
			cnt6++;
			if(cnt6 == 3) return true;
		} 
		else cnt6 = 0;
	}
	return false;
}


int main(){
	int n, i, k = 666;
	//n = 10000;
	scanf("%d", &n);
	for(i=0;i<n;k++){
		if(valid666(k)) i++;
	}
	printf("%d", k-1);
	return 0;
}
