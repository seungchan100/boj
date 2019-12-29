#include <stdio.h>

char sol[10000][10000];

void tri(int sr, int sc, int size){
	int r, c, rmax = size-1, cmax;
	for(r=0;r<rmax;r++){
		sol[sr+r][sc+r] = sol[sr+r][sc-r] = '*';
	}
	
	if(size != 3){
		size >>= 1;
		tri(sr, sc, size);
		tri(sr+size, sc-size, size);
		tri(sr+size, sc+size, size);
	}else{
		for(c=0;c<5;c++){
			sol[sr+rmax][sc-rmax+c] = '*';
		}
	}
}

inline void init(int size){
	register int r, c, cmax = size << 1;
	for(r=0;r<size;r++){
		for(c=0;c<cmax;c++){
			sol[r][c] = ' ';
		}
	}
}

inline void printSol(int size){
	register int r, c, cmax = size << 1;
	for(r=0;r<size;r++){
		printf("%s\n", sol[r]);
	}
}

int main(){
	int size;
	scanf("%d", &size);
	init(size);
	tri(0, (((size-1)<<1)>>1),size);
	printSol(size);
	return 0;
}
