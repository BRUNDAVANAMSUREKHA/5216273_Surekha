#include <stdio.h>

int sockMerchant(int n, int ar[]) {
    int pairs = 0;
    int visited[101] = {0}; 

    for (int i = 0; i < n; i++) {
        int color = ar[i];
        visited[color]++;        
    }

    for (int i = 0; i <= 100; i++) {
        pairs += visited[i] / 2;
    }

    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);

    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    int result = sockMerchant(n, ar);
    printf("%d\n", result);

    return 0;
}
