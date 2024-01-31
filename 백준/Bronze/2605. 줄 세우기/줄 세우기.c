#include <stdio.h>

int main(void) {
	int n,m,student[100];
	scanf("%d", &n);
	for (int i = 0; i < 100; i++) {
		student[i] = i + 1;
	}
	for (int k = 0; k < n; k++) {
		scanf("%d", &m);
		if (m > 0) {
			for (int a = k; a > k - m; a--) {
				int temp = student[a-1];
				student[a-1] = student[a];
				student[a] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", student[i]);
	}
	return 0;
}