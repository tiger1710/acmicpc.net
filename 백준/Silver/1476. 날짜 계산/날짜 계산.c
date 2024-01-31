#include <stdio.h>

int main(void) {
	int Earth = 1,E, Sun = 1,S, Moon = 1,M, year = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (1) {
		if (Earth == 16) {
			Earth -= 15;
		}
		if (Sun == 29) {
			Sun -= 28;
		}
		if (Moon == 20) {
			Moon -= 19;
		}
		if (Earth == E && Sun == S && Moon == M) break;
		Earth++; Sun++; Moon++; year++;
	}
	printf("%d\n", year);
	return 0;
}