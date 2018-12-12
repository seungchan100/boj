#include <stdio.h>
int lchild[30], rchild[30];
int N;

void preorder(int i) {
	putchar(i + 'A');
	if (lchild[i]) preorder(lchild[i]);
	if (rchild[i]) preorder(rchild[i]);
}

void inorder(int i) {
	if (lchild[i]) inorder(lchild[i]);
	putchar(i + 'A');
	if (rchild[i]) inorder(rchild[i]);
}

void postorder(int i) {
	if (lchild[i]) postorder(lchild[i]);
	if (rchild[i]) postorder(rchild[i]);
	putchar(i + 'A');
}

int main() {
	char a, b, c;
	scanf("%d", &N);
	while (N--) {
		scanf(" %c %c %c ", &a, &b, &c);
		if (b != '.') lchild[a - 'A'] = b - 'A';
		if (c != '.') rchild[a - 'A'] = c - 'A';
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	return 0;
}
