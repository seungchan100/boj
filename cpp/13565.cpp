#include <stdio.h>

char map[1010][1010];
int dr[] = {0, 0, 1, -1},
	dc[] = {1, -1, 0, 0};
int m, n, r, c;

inline bool valid(int nr, int nc){
	return nr >=0 && nc >=0 && nr < m && nc < n && (map[nr][nc] == '0');
}

int go(int nr, int nc){
	if(!valid(nr, nc))
		return false;
	if(nr == (m-1))
		return true;
	map[nr][nc] = '1';
	for(register int i=0;i<4;i++){
		if(go(nr+dr[i], nc+dc[i]))
			return true;
	}
	return false;
}

inline bool test(){
	for(c=0;c<n;c++){
		if(go(0, c)) return true;
	}
	return false;
}

int main(void) {
//	freopen("test.txt", "r", stdin); 
	scanf("%d %d ", &m, &n);
	for(r=0;r<m;r++){
		scanf(" %s ", map[r]);
	}
	printf("%s", test()? "YES":"NO");
	
	return 0;
}
