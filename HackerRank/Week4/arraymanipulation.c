long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long *diff = calloc(n + 2, sizeof(long)); // difference array (1-indexed)

    for (int i = 0; i < queries_rows; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        diff[a] += k;
        if (b + 1 <= n) diff[b + 1] -= k;
    }

    long max_val = 0;
    long current = 0;
    for (int i = 1; i <= n; i++) {
        current += diff[i];
        if (current > max_val) max_val = current;
    }

    free(diff);
    return max_val;
}
