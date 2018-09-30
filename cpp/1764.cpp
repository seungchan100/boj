#include <stdio.h>

struct Trie {
	bool ok;
	Trie *trie[26];
	Trie() {
		ok = false;
		for (int i = 0; i < 26; i++) trie[i] = 0;
	}
	void add(char *str) {
		if (*str) {
			int t = *str - 'a';
			if (!trie[t]) trie[t] = new Trie();
			trie[t]->add(str + 1);
		}
		else ok = true;
	}
	bool exist(char *str) {
		if (*str) {
			int t = *str - 'a';
			if (!trie[t]) return false;
			return trie[t]->exist(str + 1);
		}
		return ok;
	}
};
inline void mstrcpy(char *d, char *s) {
	register int i;
	for (i = 0; d[i] = s[i]; i++);
	d[i] = 0;
}


char str[30];
char ret[500010][30];
char *sol[500010], *tmp[500010];

inline int mstrcmp(char *a, char *b) {
	register int i;
	for (i = 0; a[i] == b[i]; i++);
	return a[i] - b[i];
}
void msort(int s, int e) {
	if (s >= e) return;
	register int m = (s + e) >> 1, i = s, j = m + 1, k = s;
	msort(s, m), msort(m + 1, e);
	while (i <= m && j <= e) {
		if (mstrcmp(sol[i], sol[j]) < 0) tmp[k++] = sol[i++];
		else tmp[k++] = sol[j++];
	}
	while (i <= m) tmp[k++] = sol[i++];
	while (j <= e) tmp[k++] = sol[j++];
	for (i = s; i <= e; i++) sol[i] = tmp[i];
}
int retcnt = 0;
int main() {
	Trie *trie = new Trie;
	register int n, m, i;
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%s", str);
		trie->add(str);
	}
	while (m--) {
		scanf("%s", str);
		if (trie->exist(str)) {
			sol[retcnt] = ret[retcnt];
			mstrcpy(ret[retcnt++], str);
		}
	}
	if (!retcnt) printf("0");
	else {
		msort(0, retcnt - 1);
		printf("%d\n", retcnt);
		for (i = 0; i < retcnt; i++) {
			printf("%s\n", sol[i]);
		}
	}
	return 0;
}
