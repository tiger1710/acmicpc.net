#include <stdio.h>

int main(void)
{
	int code,car[5],count=0;
	scanf("%d", &code);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &car[i]);
	}
	for (int k = 0; k < 5; k++) {
		if (code == car[k]) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}