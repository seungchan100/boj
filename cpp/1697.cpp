#include <stdio.h>

int target;
bool visit[200010];

struct Data {
	int time, x;
	Data(int ntime, int nx) {
		time = ntime, x = nx;
	}
	Data(){}
};
Data data[200010];
int fr, re;
inline void eq(int t, int x) {
	if (x < 0 || x > 200000) return;
	if (visit[x]) return;
	visit[x] = true;
	data[re++] = { t, x };
}
inline bool empty() {
	return fr == re;
}
inline Data *dq() {
	return empty() ? 0 : &data[fr++];
}

int n, k;
inline int bfs() {
	eq(0, n);
	while (!empty()) {
		Data *data = dq();
		if (data->x == k) {
			return data->time;
		}
		int t = data->time + 1;
		eq(t, data->x - 1);
		eq(t, data->x + 1);
		eq(t, data->x << 1);
	}
	return -1;
}


int main() {
	scanf("%d %d", &n, &k);
	printf("%d", bfs());
	return 0;
}
