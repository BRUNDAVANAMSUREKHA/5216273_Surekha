#include <stdio.h>

void mb(int q[], int n) {
    int tb = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        int start = q[i] - 2 > 0 ? q[i] - 2 : 0;
        for (int j = start; j < i; j++) {
            if (q[j] > q[i]) {
                tb++;
            }
        }
    }

    printf("%d\n", tb);
}

int main() {
    int a;
    scanf("%d", &a);
    while (a--) {
        int n;
        scanf("%d", &n);
        int q[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        mb(q, n);
    }
    return 0;
}