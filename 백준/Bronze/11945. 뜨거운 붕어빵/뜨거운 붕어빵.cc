#include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char bbang[11];
		scanf("%s", &bbang);
		for (int j = m-1; j >= 0; j--) {
			printf("%c",bbang[j]);
		}
		puts("");
	}
	
	return 0;
}