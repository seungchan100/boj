#include <stdio.h>


char cmd[15];
int N, num, fr = 15000, re = 15000, arr[30000];

inline int strcmp(char *a, char *b, int len) {
	register int i;
	for (i = 0; a[i] && b[i] && a[i] == b[i] && i<len; i++);
	return a[i] - b[i];
}

inline bool empty() {
	return fr == re;
}
inline void push_front(int num) {
	arr[--fr] = num;
}
inline void push_back(int num) {
	arr[re++] = num;
}
inline int pop_front() {
	return empty() ? -1 : arr[fr++];
}
inline int pop_back() {
	return empty() ? -1 : arr[--re];
}


int main() {
	scanf("%d", &N);
	while (N--) {
		scanf(" %s ", cmd);
		if (!strcmp(cmd, "push_back", 9)) {
			scanf(" %d ", &num);
			push_back(num);
		}
		else if (!strcmp(cmd, "push_front", 10)) {
			scanf(" %d ", &num);
			push_front(num);
		}
		else if (!strcmp(cmd, "pop_front", 9)) printf("%d\n", pop_front());
		else if (!strcmp(cmd, "pop_back", 8)) printf("%d\n", pop_back());
		else if (!strcmp(cmd, "size", 4)) printf("%d\n", re-fr);
		else if (!strcmp(cmd, "empty", 5)) printf("%d\n", empty());
		else if (!strcmp(cmd, "front", 5))  printf("%d\n", empty()? -1 : arr[fr]);
		else if (!strcmp(cmd, "back", 4)) printf("%d\n", empty()? -1:arr[re-1]);
	}
	
	return 0;
}
