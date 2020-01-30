#include <stdio.h>

int map[310][310];
int cache[310][310];

inline int max(int a, int b){
	return a>b?a:b;
}

int sol(int r, int c){
	int t;
	if(cache[r][c]) return cache[r][c];
	t = max(r?sol(r-1, c):0, c?sol(r, c-1):0);
	return cache[r][c] = map[r][c] + t;
}

int main(void) {
	register int R, C, r, c;
	//freopen("test.txt", "r", stdin); 
	
	scanf("%d %d", &R, &C);
	for(r=0;r<R;r++){
		for(c=0;c<C;c++){
			scanf("%d ", &map[r][c]);
			map[r][c]++;
		}
	}
	printf("%d", sol(R-1, C-1)-R-C+1);
	return 0;
}
