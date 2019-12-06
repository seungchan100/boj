#include <stdio.h>

bool IsVowel[100];
char vowel[10] = {
	'A','E','I','O','U','a','e','i','o', 'u'
};

inline void go(){
	int i, c=0, v=0;
	char buf[110]={0,};
	scanf(" %[^\n]s\n", &buf);
	for(i=0;buf[i];i++){
		if(IsVowel[buf[i]]) v++;
		else if(buf[i] != ' ') c++;
	}
	printf("%d %d\n", c, v);
}

int main(){
	//freopen("test.txt", "r", stdin);
	int n, i;
	scanf("%d ", &n);
	for(i=0;i<10;i++) IsVowel[vowel[i]] = true;
	while(n--){
		go();
	}
	return 0;
}
