#include <stdio.h>

int arr[100010];

int main(){
	int n, i, r = 1, max;
//	freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d", arr+i);
	max = arr[n-1];
	for(i=n-2;i>=0;i--){
		if(max < arr[i]){
			r++;
			max = arr[i];
		}
	}
	printf("%d", r);
	return 0;
}
