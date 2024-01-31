#include <stdio.h>

int main(void) {
    char num[100];
    int N, sum = 0;
    scanf("%d %s", &N, num);

    for (int i = 0; i < N; i++) {
        sum += num[i] - '0';
    }

    printf("%d\n", sum);

    return 0;
}