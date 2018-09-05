#include <stdio.h>
struct Word {
	int len, sum;
	char w[55];
};
Word data[20001];
Word *word[20001];
Word *tmp[20001];
inline int getSum(char *a) {
	register int i, sum = 0;
	for (i = 0; a[i]; i++) {
		if ('0' <= a[i] && a[i] <= '9')
			sum += a[i]-'0';
	}
	return sum;
}
inline int mstrlen(char *a) {
	register int i = 0;
	while (a[i])i++;
	return i;
}
inline int mstrcmp(char *a, char *b) {
	register int i;
	for (i = 0; a[i] && b[i] && a[i] == b[i]; i++);
	return a[i] - b[i];
}
inline int cmp(int i, int j) {
	if (word[i]->len != word[j]->len)
		return word[j]->len - word[i]->len;
	if (word[j]->sum != word[i]->sum)
		return word[j]->sum - word[i]->sum;
	return mstrcmp(word[j]->w, word[i]->w);
}
void msort(int s, int e) {
	if (s >= e) return;
	register int m = (s + e) / 2,
		i = s, j = m + 1, k = s;
	msort(i, m);
	msort(j, e);
	while (i <= m && j <= e) {
		if (cmp(i, j) > 0) tmp[k++] = word[i++];
		else tmp[k++] = word[j++];
	}
	while (i <= m)tmp[k++] = word[i++];
	while (j <= e)tmp[k++] = word[j++];
	for (i = s; i <= e; i++) word[i] = tmp[i];
}

int main() {
	register int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", data[i].w);
		data[i].len = mstrlen(data[i].w);
		data[i].sum = getSum(data[i].w);
		word[i] = &data[i];
	}
	msort(0, n - 1);
	for (i = 0; i < n; i++) {
		printf("%s\n", word[i]->w);
	}
	return 0;
}
