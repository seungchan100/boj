#include <stdio.h>
int p[100010] = { 1, 1, };
struct Node {
	int n;
	Node *next;
	Node() { n = 0; next = 0; }
	Node(int nn, Node *nnext) {
		n = nn; next = nnext;
	}
	void add(int nn) {
		next = new Node(nn, next);
	}
};
Node node[100010];
int queue[100010], fr, re;
inline void push(int n) {
	queue[re++] = n;
}
inline int pop() {
	return queue[fr++];
}
inline bool empty() { return fr == re; }

int main() {
	register int t, a, b, i;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d", &a, &b);
		node[a].add(b), node[b].add(a);
	}
	i = 1;
	push(1);
	while (!empty()) {
		i = pop();
		Node *iter = &node[i];
		while (iter = iter->next) {
			if (!p[iter->n]) {
				p[iter->n] = i;
				push(iter->n);
			}
		}
	}
	for(i=2;i<=t;i++) printf("%d\n", p[i]);
	return 0;
}
