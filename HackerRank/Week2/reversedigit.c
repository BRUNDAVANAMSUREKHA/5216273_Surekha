#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sdh(long long n) {
    if (n < 10) {
        return n;
    }
    long long s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return sdh(s);
}

int sd(char n[], int a) {
    long long s = 0;
    int len = strlen(n);
    for (int i = 0; i < len; i++) {
        s += n[i] - '0';
    }
    s *= a;
    return sdh(s);
}

int main() {
    char n[100001];
    int a;
    scanf("%s %d", n, &a);
    printf("%d\n", sd(n, a));
    return 0;
}