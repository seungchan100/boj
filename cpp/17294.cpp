#include <stdio.h>

char str[30];


int main() {
	int d;
	bool ok = true;
	scanf("%s", str);
	if (str[1]){
		d = str[1] - str[0];
		for (register int i = 2; str[i]; i++) {
			if ((str[i] - str[i - 1]) != d) {
				ok = false;
				break;
			}
		}
	}
	printf("%s", ok ? "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" : "흥칫뿡!! <(￣ ﹌ ￣)>");
	return 0;
}
