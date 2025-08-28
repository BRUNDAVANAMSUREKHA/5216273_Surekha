#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* solve(int n, int* arr, int q, int* queries, int* result_count) {
    int* ans = malloc(q * sizeof(int));

    for (int qi = 0; qi < q; qi++) {
        int k = queries[qi];

        // Deque for sliding window maximum
        int* dq = malloc(n * sizeof(int));
        int front = 0, back = -1;

        int min_of_max = INT_MAX;

        for (int i = 0; i < n; i++) {
            // Remove elements out of this window
            while (front <= back && dq[front] <= i - k) front++;

            // Remove smaller values from the back
            while (front <= back && arr[dq[back]] <= arr[i]) back--;

            dq[++back] = i;

            // First valid window starts at i >= k-1
            if (i >= k - 1) {
                int max_in_window = arr[dq[front]];
                if (max_in_window < min_of_max) min_of_max = max_in_window;
            }
        }

        ans[qi] = min_of_max;
        free(dq);
    }

    *result_count = q;
    return ans;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int* queries = malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) scanf("%d", &queries[i]);

    int result_count;
    int* result = solve(n, arr, q, queries, &result_count);

    for (int i = 0; i < result_count; i++) printf("%d\n", result[i]);

    free(arr);
    free(queries);
    free(result);

    return 0;
}
