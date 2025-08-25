#include <stdio.h>
#include <stdint.h>

unsigned int flippingBits(unsigned int n) {
    return n ^ 0xFFFFFFFF; 
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        unsigned int n;
        scanf("%u", &n);
        printf("%u\n", flippingBits(n));
    }

    return 0;
}
