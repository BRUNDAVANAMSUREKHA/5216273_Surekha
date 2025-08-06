#include <stdio.h>
void minimax(int arr[5]) 
{
    long sum = 0;
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < 5; i++) 
    {
        sum += arr[i];
        if (arr[i] < min) 
        {
            min = arr[i];
        }
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    long min_sum = sum - max;
    long max_sum = sum - min;
    printf("%ld %ld\n", min_sum, max_sum);
}
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) 
    {
        scanf("%d", &arr[i]);
    }
    minimax(arr);
    return 0;
}
