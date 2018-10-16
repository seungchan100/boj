#include <stdio.h>

typedef long long ll;
ll arr[100010];
struct Seg {
	int s, e, m;
	ll sum;
	Seg *left, *right;
	Seg(int ns, int ne) {
		s = ns, e = ne;
		if (s == e) {
			sum = arr[s];
			return;
		}
		m = (s + e) >> 1;
		left = new Seg(s, m);
		right = new Seg(m + 1, e);
		sum = left->sum + right->sum;
	}
	~Seg() {
		delete left, delete right;
	}
	void set(int a, int b) {
		if (s == e) {
			sum = b;
			return;
		}
		if (s <= a && a <= m) left->set(a, b);
		else right->set(a, b);
		sum = left->sum + right->sum;
	}
	ll getSum(int x, int y) {
		if (x <= s && e <= y) return sum;
		else if (y < s || e < x) return 0;
		else return left->getSum(x, y) + right->getSum(x, y);
	}
};
inline void swap(int *x, int *y) {
	register int t = *x;
	*x = *y, *y = t;
}
int main() {
	register int n, q, x, y, a, b;
	scanf("%d %d", &n, &q);
	for (x = 1; x <= n; x++) scanf("%lld", arr + x);
	Seg *seg = new Seg(1, n);
	while (q--) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (y < x) swap(&x, &y);
		printf("%lld\n", seg->getSum(x, y));
		seg->set(a, b);
	}
	return 0;
}
