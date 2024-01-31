#include <stdio.h>

int main(void)
{
	char dish[51];
	int height = 10;
	scanf("%s", dish);
	for (int i = 1; i < 51; i++) {
		if (dish[i] != dish[i - 1] && dish[i] == '(') {
			height += 10;
		}else if (dish[i] != dish[i - 1] && dish[i] == ')') {
			height += 10;
		}else if (dish[i]=='(') {
			height += 5;
		}else if (dish[i] == ')') {
			height += 5;
		}else {
			break;
		}
	}
	printf("%d\n", height);
	return 0;
}