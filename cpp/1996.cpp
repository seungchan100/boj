#include <stdio.h>

char imap[1010][1010];
char omap[1010][1010];
int n;

int dr[] ={-1, -1, -1, 0, 1, 1, 1, 0},
	dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	
inline bool isValid(int i, int j){
	return i>=0 && j>=0 && i<n && j<n;
}

void set(int r, int c){
	if(imap[r][c] != '.'){
		omap[r][c] = '*';
		return;
	}
	
	int i, cnt = 0, nr, nc;
	for(i=0;i<9;i++){
		nr = r+dr[i];
		nc = c+dc[i];
		if(!isValid(nr, nc))
			continue;
		cnt += (imap[nr][nc] == '.')? 0:imap[nr][nc]-'0';
	}
	omap[r][c] = (cnt>=10)? 'M':cnt+'0';
}

int main(){
	int i, j;
//	freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf(" %s ", imap[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			set(i, j);
		}
	}
	for(i=0;i<n;i++)
		printf("%s\n", omap[i]);
	return 0;
}
