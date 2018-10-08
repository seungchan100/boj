#include <stdio.h>

struct Node {
	char c;
	Node *prev, *next;
	Node(char nc, Node *nprev, Node *nnext) {
		c = nc; prev = nprev, next = nnext;
	}
	Node(){
		c = 0;
		prev = next = 0;
	}
};
Node *cur, *head, *tail;
char str[100010];
inline void input(char ch) {
	Node *nnode = new Node(ch, cur, cur->next);
	cur->next->prev = nnode;
	cur->next = nnode;
	cur = cur->next;
}
inline void left() {
	if (cur->prev) cur = cur->prev;
}
inline void right() {
	if (cur->next != tail) cur = cur->next;
}
inline void remove() {
	if (cur->c != 0) {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		Node *todel = cur;
		cur = cur->prev;
		delete todel;
	}
}
int main() {
	register int i, n;
	register char cmd;
	cur = head = new Node;
	tail = new Node(0, head, 0);
	head->next = tail;
	scanf("%s", str);
	for (i = 0; str[i]; i++) input(str[i]);
	scanf("%d", &n);
	while (n--) {
		scanf(" %c ", &cmd);
		switch (cmd) {
		case 'P':
			scanf(" %c ", &cmd);
			input(cmd);
			break;
		case 'L':left(); break;
		case 'D':right(); break;
		case 'B':remove(); break;
		}
	}
	Node *iter = head->next;
	while (iter != tail) {
		putchar(iter->c);
		iter = iter->next;
	}
	return 0;
}
