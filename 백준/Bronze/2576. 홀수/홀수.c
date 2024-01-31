#include <stdio.h>

int main(void) {
	int min=101,odd,sum=0;
	for (int i = 0; i < 7; i++) {
		scanf("%d",&odd);
		if (odd % 2 != 0) {
			sum += odd;
			min = min > odd ? odd : min;
		}
	}
	if (min == 101) {
		puts("-1");
	}
	else {
		printf("%d\n%d\n", sum,min);
	}
	return 0;
}