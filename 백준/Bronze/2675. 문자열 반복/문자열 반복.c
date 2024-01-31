#include <stdio.h>

int main(void) {
    int T;
    int R;
    char S[21];

    scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        scanf("%d %s", &R, S);

        for (char i = 0; S[i] != '\0'; i++) {
            for (int repeat = 0; repeat < R; repeat++) {
                printf("%c", S[i]);
            }
        }
        puts("");
    }

    return 0;
}