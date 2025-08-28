#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int MaxMin(int a, int a_c, int *ar) {
    qsort(ar, a_c, sizeof(int), cmp);
    int min = ar[a-1] - ar[0];
    for (int i = 1; i <= a_c - a; i++) {
        int diff = ar[i+a-1] - ar[i];
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}

int main() {
    int n, a;
    scanf("%d %d", &n, &a);
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int res = MaxMin(a, n, ar);
    printf("%d\n", res);
    return 0;
}