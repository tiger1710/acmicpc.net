#include <stdio.h>
#include "string.h"
int main(void)
{
	char name[100];
	scanf("%s", &name);
	for (char i = 97; i <= 122; i++) {
		int count = 0;
		for (int k = 0; k < strlen(name); k++) {
			if (name[k] == i) {
				count++;
			}
		}
		printf("%d ",count);
	}
	return 0;
}