#include <stdio.h>
//https://www.acmicpc.net/problem/16396


typedef struct XY{
	int x, y;
} XY;

XY data[10010];
XY *xy[10010];
XY *tmp[10010];
int n;

inline int cmp(XY *a, XY *b){
	return a->x != b->x? a->x-b->x:a->y-b->y;
}

inline int MAX(int a, int b){
	return a>b?a:b;
}

void msort(int s, int e){
	if(s>=e) return;
	int i = s, m = (s+e)>>1, j = m+1, k = s; 
	msort(s, m);
	msort(m+1, e);
	while(i <= m && j <= e){
		tmp[k++] = (cmp(xy[i], xy[j]) <= 0) ?
			xy[i++]:xy[j++];
	}
	while(i<=m) tmp[k++] = xy[i++];
	while(j<=e) tmp[k++] = xy[j++];
	for(i=s;i<=e;i++) xy[i] = tmp[i];
}


int solve(){
	int i, sol = 0, min = xy[0]->x, max = xy[0]->y;
	for(i=1;i<n;i++){
		if(xy[i]->x <= max) max = MAX(max, xy[i]->y);
		else{
			sol += max-min;
			min = xy[i]->x, max = MAX(max, xy[i]->y);
		}
	}
	sol += max-min;
	return sol;
}


int main(){
	int i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &data[i].x, &data[i].y);
		xy[i] = &data[i];
	} 
	msort(0, n-1);
	printf("%d", solve());
	return 0;
}
