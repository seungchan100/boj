#include <stdio.h>

inline char run(){
	char buf[110] = {0,};
	int a=0, b=0, c=0, d=0, i;
	scanf("%[^\n]s", buf);
	getchar();
	if(!buf[0]) return 0;
	for(i=0;buf[i];i++){
		if('a' <= buf[i] && buf[i] <= 'z') a++;
		else if('A' <= buf[i] && buf[i] <= 'Z') b++;
		else if('0' <= buf[i] && buf[i] <= '9') c++;
		else if(buf[i] == ' ') d++;
	}
	printf("%d %d %d %d\n", a, b, c, d);
	return 1;
}

int main(){
//	freopen("test.txt", "r", stdin);
	while(run());
	return 0;
}
