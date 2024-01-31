#include <stdio.h>

int main(void)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int smonth, sdate,print=0;
	scanf("%d %d", &smonth, &sdate);

	for (int i = 0; i < smonth; i++) {
		if (i == 0) {
			continue;
		}
		print += month[i-1];
	}
	print += sdate;
	print %= 7;
	switch (print) {
		case 1: printf("MON"); break;
		case 2: printf("TUE"); break;
		case 3: printf("WED"); break;
		case 4: printf("THU"); break;
		case 5: printf("FRI"); break;
		case 6: printf("SAT"); break;
		case 0: printf("SUN"); break;
	}
	return 0;
}