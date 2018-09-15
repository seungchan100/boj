#include <stdio.h>
typedef unsigned long long ll;
ll heap[2020], last = 0;
inline void swap(ll &a, ll &b) {
	ll t = a;
	a = b, b = t;
}
inline int parent(int a) {
	return a >> 1;
}
inline int left(int a) {
	return a << 1;
}
inline int right(int a) {
	return (a << 1) + 1;
}
inline void push(ll a) {
	heap[++last] = a;
	int p = parent(last),
		c = last;
	while (c > 1 && heap[p] > heap[c]) {
		swap(heap[p], heap[c]);
		c = p, p = parent(c);
	}
}
inline bool empty() {
	return !last;
}
inline ll pop() {
	if (empty()) return 0;
	ll t = heap[1];
	heap[1] = heap[last--];
	int p = 1, c, lc, rc;
	while (p < last) {
		lc = left(p), rc = right(p);
		if (rc <= last) c = heap[lc] < heap[rc] ? lc : rc;
		else if (lc <= last) c = lc;
		if (heap[c] >= heap[p]) break;
		swap(heap[c], heap[p]);
		p = c;
	}
	return t;
}
int main() {
	int n, m, a;
	ll b;
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%d", &a);
		push(a);
	}
	while (m--) {
		b = pop() + pop();
		push(b), push(b);
	}
	b = 0;
	while (!empty()) {
		b += pop();
	}
	printf("%llu", b);
	return 0;
}
