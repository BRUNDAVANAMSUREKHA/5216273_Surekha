#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int cmpDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

char* twoArrays(int k, int n, int A[], int B[]) {
    qsort(A, n, sizeof(int), cmpAsc);
    qsort(B, n, sizeof(int), cmpDesc);

    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int A[n], B[n];
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        printf("%s\n", twoArrays(k, n, A, B));
    }

    return 0;
}
