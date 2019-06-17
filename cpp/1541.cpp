#include <stdio.h>


int main() {
	int num = 0, sum = 0;
	char str[60] = { 0, }, minus = 0;
	scanf("%s", str);
	for (register int i = 0; str[i]; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num = num * 10 + str[i] - '0';
		}
		else if (str[i] == '+') {
			sum = sum + ((minus) ? -1 * num : num);
			num = 0;
		}
		else if (str[i] == '-'){
			sum = sum + ((minus) ? -1 * num : num);
			minus = 1;
			num = 0;
		}
	}
	sum = sum + ((minus) ? -1 * num : num);
	printf("%d", sum);

	return 0;
}
