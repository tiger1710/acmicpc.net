#include <stdio.h>
#include <string.h>

int isPalin(char a[], int s,int n) {
	if (s > n) return 1;
	if (a[s] == a[n - 1]) {
		return isPalin(a, s+1, n-1);
	}
	return 0;
}

int main(void)
{
	int result;
	char word[20];
	scanf("%s", word);
	result=isPalin(word,0,strlen(word));
	if (result) {
		puts("true");
	}
	else {
		puts("false");
	}
	return 0;
}