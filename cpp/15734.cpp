#include <stdio.h>

inline int min(int a, int b){
	return a<b?a:b;
}

int main(){
	int l, r, a, s, b;
	scanf("%d %d %d", &l, &r, &a);
	if(l<r)
		s = l, b = r;
	else 
		s = r, b = l;
	l = min(a, b-s);
	s += l;
	a -= l;
	printf("%d", (s<<1)+(a>0? (a>>1)<<1:0));
	return 0;
}
