#include <stdio.h>
int main(void) {
	
	for (int i = 0; i < 3; i++) {
		int bestcount = 0;
		char num[9];
		int count = 1;
		scanf("%s", &num);
		for (int k = 1; k < 9; k++) {
			if (num[k] == num[k - 1]) {
				count++;
			}
			else {
				if(count>bestcount)
					bestcount = count;
				count = 1;
				continue;
			}
		}
		printf("%d\n", bestcount);
	}
	return 0;
}