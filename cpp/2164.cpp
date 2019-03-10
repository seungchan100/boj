#include <stdio.h>
struct Link {
	int n;
	Link *next;
	Link(int nn) {
		n = nn;
	}
};

int main() {
	register int i,n;
	scanf("%d", &n);
	Link *head, *last, *newLink, *current;
	head = new Link(1);
	current = head;
	for (i = 2; i <= n; i++) {
		newLink = new Link(i);
		current->next = newLink;
		current = newLink;
	}
	last = current;
	current = head;
	while (n != 1) {
		current = current->next;
		n--;
		if (n == 1) break;
		last->next = current;
		last = last->next;
		current = current->next;
		last->next = 0;
	}
	printf("%d", current->n);
	return 0;
}
