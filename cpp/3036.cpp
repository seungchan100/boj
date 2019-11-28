#include <stdio.h>

int gcd(int a, int b){
	return b? gcd(b, a%b):a;
}

int main(){
    int t, a, b, g;
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &t, &a);t--;
    while(t--){
    	scanf("%d", &b);
    	g = gcd(a, b);
    	printf("%d/%d\n", a/g, b/g);
	  }
    return 0;
}
