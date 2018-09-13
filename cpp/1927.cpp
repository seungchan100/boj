#include <stdio.h>
inline int left(int a) {
	return a << 1;
}
inline int right(int a) {
	return (a << 1) + 1;
}
inline int parent(int a) {
	return a >> 1;
}
inline void swap(int &a, int &b) {
	int t = a;
	a = b, b = t;
}
int heap[100010];
int last;
inline bool empty() {
	return !last;
}
void push(int a) {
	heap[++last] = a;
	int c = last, p = parent(c);
	while (p >= 1) {
		if (heap[c] >= heap[p]) break;
		swap(heap[c], heap[p]);
		c = p, p = parent(c);
	}
}
int pop() {
	if (empty()) return 0;
	int p, c, lc, rc, t;
	t = heap[1];
	heap[1] = heap[last--];
	p = 1;
	while (p <= last) {
		lc = left(p), rc = right(p);
		if (rc <= last) c = heap[lc] < heap[rc] ? lc : rc;
		else if (lc <= last) c = lc;
		else break;
		if (heap[c] < heap[p]) swap(heap[c], heap[p]);
		else break;
		p = c;
	}
	return t;
}
int main() {
	register int n, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (x) push(x);
		else printf("%d\n", pop());
	}
	return 0;
}
