#include <stdio.h>

int gcnt;
struct Group {
	int cnt;
	bool a[210];
};
Group group[210];
int N, M;

inline void addGroup(int i, int j) {
	register int x, y;
	for (x = 0; x < gcnt; x++) {
		if (group[x].a[j]) {
			group[x].a[i] = true; return;
		}
		else if (group[x].a[i]) {
			group[x].a[j] = true; return;
		}
	}
	group[gcnt].a[i] = group[gcnt].a[j] = true;
	gcnt++;
}

inline bool enable() {
	register int a, i, j;
	register bool ret = false;
	scanf("%d", &a);
	for (i = 0; i < gcnt; i++) {
		if (group[i].a[a]) {
			ret = true;
			for (j = 1; j < M; j++) {
				scanf("%d", &a);
				if (!group[i].a[a]) ret = false;
			}
			return ret;
		}
	}
	return false;
}

int main() {
	register int i, j, a, jmax;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &a);
			if (a || i==j) addGroup(i, j);
		}
	}
	printf("%s", enable() ? "YES" : "NO");
	return 0;
}
