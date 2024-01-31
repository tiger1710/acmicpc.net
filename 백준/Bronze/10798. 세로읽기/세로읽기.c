#include <stdio.h>

int main(void)
{
	char arr[5][16] = { 0, };
	for (int i = 0; i < 5; i++) {
		scanf("%s", arr[i]);
	}
	for (int i = 0; i <16 ; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[k][i] == 0) continue;
			printf("%c", arr[k][i]);
		}
	}
	puts("");

	return 0;
}