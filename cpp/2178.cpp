#include <stdio.h>
int R, C, r, c;
char map[110][110];

struct Data{
	int r, c, t;
	Data(){
		r=c=t=0;
	}
	Data(int nr, int nc, int nt){
		r = nr, c = nc, t = nt;
	}
	void set(int nr, int nc, int nt){
		r = nr, c = nc, t = nt;
	}
};
Data queue[110*110];
int fr, re;
bool empty(){
	return fr==re;
}
bool visit[110][110];
inline void push(int nr, int nc, int nt){
	if(visit[nr][nc]) return;
	if(nr < 0 || nc <0 || nr >=R || nc >= C) return;
	if(map[nr][nc] == '0') return;
	visit[nr][nc] = true;
	queue[fr++].set(nr, nc, nt);
}
inline Data *pop(){
	return empty()? 0:&queue[re++];
}

int dr[] = {0, 0, 1, -1},
dc[] = {1, -1, 0, 0};
int main() {
	scanf("%d %d", &R, &C);
	for(r=0;r<R;r++){
		scanf("%s", map[r]);
	}
	register int er = R-1, ec = C-1, i;
	push(0, 0, 1);
	Data *dt;
	while(!empty()){
		dt = pop();
		if(dt->r == er && dt->c == ec ){
			break;
		}
		for(i=0;i<4;i++){
			push(dt->r+dr[i], dt->c+dc[i], dt->t+1);
		}
	}
	printf("%d\n", dt->t);
}
