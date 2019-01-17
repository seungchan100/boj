#include <stdio.h>
int L, C, ch;
bool arr[30];
char str[20];
inline bool isMo(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void print(int number, int lastIdx) {
	register int i;
	if (number == L) {
		register int mo = 0, ja = 0;
		for (i = 0; i < number; i++) {
			isMo(str[i]) ? mo++ : ja++;
		}
		if(mo >= 1 && ja >=2)
			printf("%s\n", str);
		return;
	}
	
	for (i = lastIdx; i <= 26; i++) {
		if (arr[i]) {
			str[number] = i + 'a';
			print(number + 1, i + 1);
		}
	}
}
int main() {
	scanf("%d %d", &L, &C);
	while (C--) {
		scanf(" %c ", &ch);
		arr[ch - 'a'] = true;
	}
	print(0, 0);
	return 0;
}
