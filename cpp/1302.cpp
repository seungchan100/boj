#include <stdio.h>
int max = 0;
char ret[60];

inline void mstrcpy(char *d, char *s) {
	register int i;
	for (i = 0; d[i] = s[i]; i++);
	d[i] = 0;
}
inline int mstrcmp(char *a, char *b) {
	register int i;
	for (i = 0; a[i] && b[i] && a[i] == b[i]; i++);
	return a[i] - b[i];
}
struct Trie {
	int n;
	Trie *trie[26];
	Trie() {
		n = 0;
		for (int i = 0; i < 26; i++) trie[i] = 0;
	}
	void add(char *str, char *ori) {
		if (*str) {
			int t = *str - 'a';
			if (!trie[t]) trie[t] = new Trie();
			trie[t]->add(str + 1, ori);
		}
		else {
			++n;
			if (max < n) {
				max = n;
				mstrcpy(ret, ori);
			}
			else if (max == n && (mstrcmp(ori, ret) < 0)) {
				mstrcpy(ret, ori);
			}
		}
	}
};

char str[60];
int main() {
	Trie *trie = new Trie;
	register int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		trie->add(str, str);
	}
	printf("%s", ret);
	return 0;
}
