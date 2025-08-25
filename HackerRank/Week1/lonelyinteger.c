#include <stdio.h>

int lonelyinteger(int n, int a[]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= a[i];
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = lonelyinteger(n, a);
    printf("%d\n", ans);

    return 0;
}
