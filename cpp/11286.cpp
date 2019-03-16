#include <stdio.h>
//https://www.acmicpc.net/problem/11286
// 작은수가 젤 위에 

inline int left(int n) {
	return n << 1;
}
inline int right(int n) {
	return (n << 1) + 1;
}
inline int parent(int n) {
	return n >> 1;
}
int last = 1;
int heap[200000];
inline bool empty() {
	return last == 1;
}
inline int abs(int a) {
	return a > 0 ? a : -a;
}
inline int cmp(int a, int b) {
	return abs(a) == abs(b) ? a - b : abs(a) - abs(b);
}
inline void swap(int *a, int *b) {
	register int t = *a;
	*a = *b, *b = t;
}
inline void push(int n) {
	register int c, p;
	c = last;
	heap[last++] = n;
	while (c != 1) {
		p = parent(c);
		if (cmp(heap[c], heap[p]) >= 0) break;
		swap(&heap[c], &heap[p]);
		c = p;
	}
}
inline int pop() {
	if (empty()) return 0;
	int ret = heap[1];
	register int p, c, lc, rc;
	heap[1] = heap[--last];
	p = 1;
	while (1) {
		if (p == last) break;
		lc = left(p), rc = right(p);
		if (rc > last) break;
		c = lc == last ? lc : cmp(heap[lc], heap[rc]) <= 0 ? lc : rc;
		if (cmp(heap[p], heap[c]) <= 0) break;
		swap(&heap[p], &heap[c]);
		p = c;
	}
	return ret;
}


int main() {
	register int n, a;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		if (a) push(a);
		else printf("%d\n", pop());
	}
	return 0;
}



