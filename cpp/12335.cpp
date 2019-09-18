//	https://www.acmicpc.net/problem/12335

#include <stdio.h>

char map[10][10] = { 0, };

inline char rowCheck(int r) {
	register int c;
	int ocnt = 0, tcnt = 0, xcnt = 0;
	char sol = 'N';
	for (c = 0; c < 4; c++) {
		switch (map[r][c]) {
		case 'O': ocnt++; break;
		case 'T': tcnt++; break;
		case 'X': xcnt++; break;
		}
	}

	if (ocnt == 4 || ((ocnt == 3) && (tcnt == 1))) sol = 'O';
	if (xcnt == 4 || ((xcnt == 3) && (tcnt == 1))) sol = 'X'; 
	return sol;
}

inline char colCheck(int c) {
	register int r;
	int ocnt = 0, tcnt = 0, xcnt = 0;
	char sol = 'N';
	for (r = 0; r < 4; r++) {
		switch (map[r][c]) {
		case 'O': ocnt++; break;
		case 'T': tcnt++; break;
		case 'X': xcnt++; break;
		}
	}
	if (ocnt == 4 || ((ocnt == 3) && (tcnt == 1))) sol = 'O';
	if (xcnt == 4 || ((xcnt == 3) && (tcnt == 1))) sol = 'X';
	return sol;
}

inline char ldiagonalCheck() {
	register int r;
	char sol = 'N';
	int ocnt = 0, tcnt = 0, xcnt = 0;
	for (r = 0; r < 4; r++) {
		switch (map[r][r]) {
		case 'O': ocnt++; break;
		case 'T': tcnt++; break;
		case 'X': xcnt++; break;
		}
	}
	if (ocnt == 4 || ((ocnt == 3) && (tcnt == 1))) sol = 'O';
	if (xcnt == 4 || ((xcnt == 3) && (tcnt == 1))) sol = 'X';
	return sol;
}

inline char rdiagonalCheck() {
	register int r;
	char sol = 'N';
	int ocnt=0, tcnt=0, xcnt = 0;
	for (r = 0; r < 4; r++) {
		switch (map[r][3-r]) {
		case 'O': ocnt++; break;
		case 'T': tcnt++; break;
		case 'X': xcnt++; break;
		}
	}
	if (ocnt == 4 || ((ocnt == 3) && (tcnt == 1))) sol = 'O';
	if (xcnt == 4 || ((xcnt == 3) && (tcnt == 1))) sol = 'X';
	return sol;
}

inline bool isExistEmpty() {
	register int r, c;
	for (r = 0; r < 4; r++)
		for (c = 0; c < 4; c++)
			if (map[r][c] == '.') return true;
	return false;
}

inline char test() {
	register int i;
	char sol = 'N';
	
	for (i = 0; i < 4; i++)
		scanf(" %s ", map[i]);
	//scanf(" %s ");
	for (i = 0; i < 4; i++) {
		sol = rowCheck(i);
		if (sol != 'N') return sol;
		sol = colCheck(i);
		if (sol != 'N') return sol;
		//printf("%s\n", map[i]);
	}

	sol = ldiagonalCheck();
	if (sol != 'N') return sol;
	sol = rdiagonalCheck();
	if (sol != 'N') return sol;
	
	return isExistEmpty() ? 'N' : 'D';
	
}

int main() {
	int t, i;
	char sol;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		sol = test();
		switch (sol) {
		case 'N':printf("Game has not completed\n");
			break;
		case 'D': printf("Draw\n");
			break;
		default:
			printf("%c won\n", sol);
		}
	}
	return 0;
}
