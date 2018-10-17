#include <stdio.h>

struct Node {
	int n;
	Node *next;
	Node() {
		next = 0;
	}
	Node(int nn, Node *nnext) {
		n = nn; next = nnext;
	}
	~Node() {
		delete next;
	}
};
struct List {
	Node *head, *tail;
	List() {
		head = tail = new Node();
	}
	inline void add(int nn) {
		Node *nnode = new Node(nn, 0);
		Node *iter = head, *prev = head;
		while (iter = iter->next) {
			if (iter->n >= nn) break;
			prev = iter;
		}
		prev->next = nnode;
		nnode->next = iter;
	}
};

List list[1010];
bool visit[2][1010];

void dfs(int n) {
	if (visit[0][n]) return;
	visit[0][n] = true;
	printf("%d ", n);
	Node *iter = list[n].head;
	while (iter = iter->next) {
		dfs(iter->n);
	}
}

int queue[1010], fr, re;
inline bool empty() {
	return fr == re;
}
inline void eq(int n) {
	if (visit[1][n]) return;
	visit[1][n] = true;
	queue[re++] = n;
}
inline int dq() {
	return queue[fr++];
}
void bfs(int n) {
	eq(n);
	while (!empty()) {
		int t = dq();
		printf("%d ", t);
		Node *iter = list[t].head;
		while (iter = iter->next) {
			eq(iter->n);
		}
	}
}

int main() {
	register int n, m, v, i, a, b;
	scanf("%d %d %d", &n, &m, &v);
	while (m--) {
		scanf("%d %d", &a, &b);
		list[a].add(b);
		list[b].add(a);
	}
	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}
