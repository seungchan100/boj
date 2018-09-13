#include <stdio.h>
#define INF 9876543210
int arr[100010];
inline int MAX(int a, int b) {
	return a > b ? a : b;
}
inline int MIN(int a, int b) {
	return a < b ? a : b;
}
struct Seg {
	Seg *left, *right;
	int s, e, max, min, m;
	Seg(int ns, int ne) {
		s = ns, e = ne, m = (s + e) >> 1;
		if (ns == ne) {
			max = min = arr[s]; return;
		}
		left = new Seg(s, m), right = new Seg(m + 1, e);
		min = MIN(left->min, right->min),
		max = MAX(left->max, right->max);
	}
	int minq(int ns, int ne) {
		if (e < ns || ne < s) return INF;
		if (ns <= s && e <= ne) return min;
		return MIN(left->minq(ns, ne), right->minq(ns, ne));
	}
	int maxq(int ns, int ne) {
		if (e < ns || ne < s) return -INF;
		if (ns <= s && e <= ne) return max;
		return MAX(left->maxq(ns, ne), right->maxq(ns, ne));
	}
};
int main() {
	register int n, m, i, a, b;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", arr + i);
	}
	Seg *seg = new Seg(1, n);
	while (m--) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", seg->minq(a, b), seg->maxq(a, b));
	}
	return 0;
}
