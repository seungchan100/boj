#include <stdio.h>

int arr[100010] = {987654321,0,};

inline int MINI(int a, int b){
	return arr[a]>arr[b]?b:a;
}
typedef struct Tree{
	int s, e;
	int mini;
	Tree *left, *right;
	Tree(int ns, int ne){
		s = ns, e = ne;
		if(s >= e){
			mini = s;
			return;
		}
		
		int m = (s+e) >> 1;
		left = new Tree(s, m);
		right = new Tree(m+1, e);
		mini = MINI(left->mini, right->mini);
	}
	void mod(int i, int a){
		if((s == e) && (s == i)){
			arr[i] = a;
			return;
		}
		int m = (s+e) >> 1;
		if(s <= i && i <= m) left->mod(i, a);
		else right->mod(i, a);
		mini = MINI(left->mini, right->mini);
	}
	int Mini(int qs, int qe){
		if(qs <= s && e <= qe) return mini;
		else if(qe < s || qs > e) return 0;
		return MINI(left->Mini(qs, qe), right->Mini(qs, qe));
	}
	
} Tree;

Tree *tree;
int main(void) {
	freopen("test.txt", "r", stdin); 
	int i, N, M, a, b, c;
	scanf("%d", &N);
	for(i=1;i<=N;i++) scanf("%d", arr+i);
	tree = new Tree(1, N);
	scanf("%d", &M);
	while(M--){
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1){
			tree->mod(b, c);
		}else{
			printf("%d\n", tree->Mini(b, c));
		}
	}
	return 0;
}
