#include <stdio.h>


int main(void) {
	int n[8], ascending[8] = { 1,2,3,4,5,6,7,8 }, descending[8] = { 8,7,6,5,4,3,2,1 };
	int D = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &n[i]);
	}
	
	for (int k = 0; k < 8; k++) {
		if (n[k] == ascending[k]) {
			D++;
		}
		else if (n[k] == descending[k]) {
			D--;
		}
	}
	if (D == 8) {
		puts("ascending");
	}
	else if (D == -8) {
		puts("descending");
	}
	else {
		puts("mixed");
	}
	
	return 0;
}