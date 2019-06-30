#include <stdio.h>

typedef struct Node {
	int num;
	Node *next;
	Node(int nnum) {
		num = nnum; next = 0;
	}
} Node;
int n;
Node *head, *tail;


int main() {
	register int i;
	scanf("%d", &n);
	head = tail = new Node(1);
	for (i = 2; i <= n; i++) {
		tail->next = new Node(i);
		tail = tail->next;
	}
	while (n != 1) {
		printf("%d\n", head->num);
		head = head->next;
		tail->next = new Node(head->num);
		tail = tail->next;
		head = head->next;
		n--;
	}
	printf("%d", tail->num);
	return 0;
}
