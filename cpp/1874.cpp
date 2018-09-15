#include <stdio.h>
int arr[100010], top, k;
char op[2000010];
inline bool empty() {
	return !top;
}
inline void push(int a) {
	arr[top++] = a;
	op[k++] = '+';
}
inline int pop() {
	op[k++] = '-';
	return empty() ? -1 : arr[--top];
}
inline bool can() {
	register int i = 1, t, p = 0, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		while (1) {
			if (n >= i) push(i++);
			else {
				p = pop();
				if (p == n) break;
				else if (p == -1) return false;
			}
		}
	}
	return true;
}
int main() {
	register int i;
	if (can()) {
		for (i = 0; op[i]; i++) printf("%c\n", op[i]);
	}
	else printf("NO");
	
	return 0;
}
