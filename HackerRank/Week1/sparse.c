#include <stdio.h>
#include <string.h>

int main() {
    int n, q;
    scanf("%d", &n);

    char strings[n][101];  
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    scanf("%d", &q);
    char queries[q][101];
    for (int i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    }

    for (int i = 0; i < q; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
