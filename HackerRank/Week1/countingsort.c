#include <stdio.h>

void countingSort(int n, int arr[]) {
    int freq[100] = {0}; 
    
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;  
    }
    
    for (int i = 0; i < 100; i++) {
        printf("%d", freq[i]);
        if (i != 99) printf(" "); 
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    countingSort(n, arr);
    return 0;
}
