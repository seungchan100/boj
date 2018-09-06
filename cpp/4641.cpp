#include<cstdio>

int uniq = 1, num[220], arr[20];
int main() {
	register int i = 0, r;
	while (1) {
		scanf("%d", arr+i);
		if (!arr[i]) {
			r = 0;
			while (--i > -1) {
				if (num[arr[i] << 1] == uniq) r++;
			}
			printf("%d\n", r);
			uniq++;
			i = 0;
		}
		else if (arr[i] < 0) break;
		else num[arr[i++]] = uniq;
	}
}
