#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a;
    scanf("%d%d", &n, &a);

    int *s[n];
    int sz[n];
    for (int i = 0; i < n; i++) {
        s[i] = NULL;
        sz[i] = 0;
    }

    int lastAnswer = 0;

    for (int i = 0; i < a; i++) {
        int type, b, c;
        scanf("%d%d%d", &type, &b, &c);
        int idx = (b ^ lastAnswer) % n;

        if (type == 1) {
            sz[idx]++;
            s[idx] = realloc(s[idx], sz[idx] * sizeof(int));
            s[idx][sz[idx] - 1] = c;
        } else if (type == 2) {
            lastAnswer = s[idx][c % sz[idx]];
            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++) {
        free(s[i]);
    }

    return 0;
}