#include <stdio.h>

char cmd[100010];
int numcnt;
int num[100010];
int left, right;
int dir;

inline void getnum() {
	char ch;
	int i = 0;
	scanf(" %c", &ch);
	while (1) {
		scanf("%d", &num[i++]);
		scanf("%c", &ch);
		if (ch == ']') break;
	}
}

inline bool startAndIsError() {
	register int i;
	for (i = 0; cmd[i]; i++) {
		if (cmd[i] == 'R') {
			dir *= -1;
		}
		else {	//	
			if (right < left) return true;
			if (dir == 1) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	return false;
}

inline void printArr() {
	register int i = (dir == 1)? left:right;
	printf("[");
	while (1) {
		if (right < left) break;
		printf("%d", num[i]);
		i += dir;
		if ((i < left) || (i > right)) break;
		printf(",");
	}
	printf("]\n");
}

int main() {
	register int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", cmd);
		scanf("%d", &numcnt);
		getnum();
		dir = 1, left = 0, right = numcnt - 1;
		if (startAndIsError()) {
			printf("error\n");
		}
		else {
			printArr();
		}
	}
	return 0;
}
