#include <stdio.h>

typedef struct List {
	bool check; int pri;
	List *next;
	~List() {
		delete next;
	}
	List(bool ncheck, int npri) {
		next = 0;
		check = ncheck;
		pri = npri;
	}
} _List;
List *head, *tail;

void append(bool check, int pri) {
	tail->next = new List(check, pri);
	tail = tail->next;
}


void solve() {
	int pri[15] = { 0, };
	int n, o, i, k, sol = 1;
	delete head;
	head = tail = new List(0, -1);
	scanf("%d %d", &n, &o);
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		pri[k]++;
		append(o == i, k);
	}
	List *p = head->next;
	while (1) {
		bool isAppend = false;
		for (i = 9; i > p->pri; i--) {
			if (pri[i] > 0) {
				isAppend = true;
				break;
			}
		}
		if (isAppend) {
			append(p->check, p->pri);
		}
		else {
			if (p->check) break;
			sol++;
			pri[p->pri]--;
		}
		p = p->next;
	}
	printf("%d\n", sol);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
