#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int k = n - i - 1; k > 0; k--) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("*");
		}
		puts("");
	}
	for(int i=1;i<n;i++){
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int k = n - i;k>0;k--) {
			printf("*");
		}
		
		puts("");
	}
	return 0;
}