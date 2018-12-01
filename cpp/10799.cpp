#include <stdio.h>


char str[100010];
char stack[100010];
int top, cnt;
inline void push(char ch) {
	stack[top++] = ch;
}
inline char pop() {
	return stack[--top];
}
int main() {
	register int i, ret = 0;
	scanf("%s", str);
	for (i = 0; str[i]; i++) {
		if (str[i] == '(') {
			push(str[i]);
		}
		else {	//	')'
			pop();
			if(str[i-1] == '(') ret += top;
			else ret++;
		}
	}
	printf("%d", ret);
	return 0;
}
