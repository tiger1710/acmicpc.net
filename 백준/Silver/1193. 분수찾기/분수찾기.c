#include <stdio.h>

//4472
int sigmaN(int n) {
	return n*(n + 1) / 2;
}

int main(void)
{
	int i,locate,p;
	scanf("%d", &locate);
	
	for (i = 1; i < 4473; i++) {
		if (sigmaN(i) >= locate) {
			p = locate-sigmaN(i-1);
			break;
		}
	}
	if (i % 2) {
		printf("%d/%d\n",i-p+1,p);
	}
	else {
		printf("%d/%d\n",p,i-p+1);
	}

	return 0;
}