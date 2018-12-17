#include <stdio.h>
int arr[10][10];
bool show[10];
inline void initShow() {
	register int i;
	for (i = 1; i <= 9; i++) show[i] = false;
}
inline bool isAllShowCheck() {
	register int i;
	for (i = 1; i <= 9; i++) if (!show[i]) return false;
	return true;
}
inline bool correct() {
	register int r, c, i, j;
	for (r = 0; r < 9; r++) {
		initShow();
		for (c = 0; c < 9; c++) {
			show[arr[r][c]] = true;
		}
		if (!isAllShowCheck()) return false;
	}

	for (r = 0; r < 9; r++) {
		initShow();
		for (c = 0; c < 9; c++) {
			show[arr[c][r]] = true;
		}
		if (!isAllShowCheck()) return false;
	}

	for (r = 0; r < 9; r += 3) {
		for (c = 0; c < 9; c += 3) {
			initShow();
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					show[arr[r + i][c + j]] = true;
				}
			}
			if (!isAllShowCheck()) return false;
		}
	}
	return true;
}
int main() {
	register int i, t, r, c;
	scanf("%d", &t);
	for(i = 1;i<=t;i++){
		for (r = 0; r < 9; r++)for (c = 0; c < 9; c++)scanf("%d", &arr[r][c]);
		printf("Case %d: %sCORRECT\n", i, correct() ? "" : "IN");
	}
	return 0;
}
