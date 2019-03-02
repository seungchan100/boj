#include <stdio.h>

char stack[110];
int top;
inline bool empty() {
	return !top;
}

inline void push(char a) {
	stack[top++] = a;
}
inline char pop() {
	return empty() ? 0 : stack[--top];
}

inline int sol() {
	char str[110] = { 0, };
	scanf("%[^\n]", str);
	if (str[0] == '.' && !str[1]) return 0;
	top = 0;
	for (register int i=0; str[i]; i++) {
		if (str[i] == '[' || str[i] == '(') push(str[i]);
		else if (str[i] == ']') {
			if (!empty() && stack[top - 1] == '[') pop();
			else return -1;
		} 
		else if (str[i] == ')') {
			if (!empty() && stack[top - 1] == '(') pop();
			else return -1;
		}
	}
	return empty()? 1:-1;
}

int main() {
	int ret;
	while (1) {
		ret = sol();
		if (ret == 1) printf("yes\n");
		else if(ret == -1) printf("no\n");
		else break;
		getchar();
	}
	return 0;
}
