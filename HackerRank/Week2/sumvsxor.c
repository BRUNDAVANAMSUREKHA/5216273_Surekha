#include <stdio.h>
#include <stdint.h>

long sumxor(long n) {
    if (n == 0) return 1;

    int zb = 0;
    long t = n;

    while (t > 0) {
        if ((t & 1) == 0) zb++;
        t >>= 1;
    }

    long result = 1L << zb;
    return result;
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", sumxor(n));
    return 0;
}