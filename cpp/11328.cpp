#include <stdio.h>

bool run() {
	int numa[150] = { 0, }, numb[150] = { 0, };
	char stra[1010] = { 0, }, strb[1010] = { 0, };
	scanf(" %s %s ", stra, strb);
	register int i;
	for (i = 0; stra[i]; i++) {
		numa[stra[i]]++;
		numb[strb[i]]++;
	}
	for (i = 'a'; i <= 'z'; i++) if (numa[i] != numb[i]) return false;
	return true;
}


int main() {
	int n;
	scanf("%d", &n);
	while (n--) printf("%sossible\n", run() ? "P" : "Imp");
	return 0;
}
