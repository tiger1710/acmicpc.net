#include <stdio.h>

int main(void) {
	int nine[9]; int sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &nine[i]);
		sum += nine[i];
	}
	sum -= 100;

	for (int i = 0; i < 9 - 1; i++) {
		for (int k = 0; k < 9 - i - 1; k++) {
			if (nine[k] > nine[k + 1]) {
				int t = nine[k];
				nine[k] = nine[k + 1];
				nine[k + 1] = t;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		int flag = 1;
		for (int k = 0; k < 9; k++) {
			if (nine[i] + nine[k] == sum) {
				nine[i] = 0;
				nine[k] = 0;
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}

	for (int i = 0; i < 9; i++) {
		if (nine[i]) printf("%d\n", nine[i]);
	}
	

	return 0;
}