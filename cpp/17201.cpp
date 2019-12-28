#include <stdio.h>

inline bool solve(){
	int n, i;
	char str[20] = {0,};
	scanf("%d %s ", &n, str);
	n <<= 1, n--;
	for(i=0;i<n;i++){
		if(str[i] == str[i+1])
			return false;
	}
	return true;
}

int main(){
//	freopen("test.txt", "r", stdin);
	printf("%s", solve()?"Yes":"No");
	return 0;
}
