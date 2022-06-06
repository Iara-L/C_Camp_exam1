#include <stdio.h>
#include <stdint.h>

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
unsigned onesCount(unsigned mask);
void flipOddBits(uint64_t* mask);
void mirrorBits(uint16_t* mask);
void toBin(unsigned n);

int main() {
    unsigned count = 0;
    uint64_t mask1;
    uint32_t mask2;
    uint16_t mask3;
    uint8_t mask4;

    scanf("%ld %u %hu %hhu", &mask1, &mask2, &mask3, &mask4);

    count = bitsNCount(mask1, mask2, mask3, mask4);

    printf("\n");
    toBin(mask1);
    printf("\n");
    toBin(mask2);
    printf("\n");
    toBin(mask3);
    printf("\n");
    toBin(mask4);
    printf("\n");

    printf("%d\n", count);

    printf("\nMirror\n");
    mirrorBits(&mask3);
    toBin(mask3);
    printf("\n\nFlip odd\n");
    flipOddBits(&mask4);
    toBin(mask4);

    return 0;
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4) {
    int counter = 0;

    counter += onesCount(mask1);
    counter += onesCount(mask2);
    counter += onesCount(mask3);
    counter += onesCount(mask4);

    return counter;
}

unsigned onesCount(unsigned mask) {
    int counter = 0;

    while (mask) {
        mask &= (mask - 1), counter++;
    }
    return counter;
}

void flipOddBits(uint64_t* mask)
{
    for (int i = 0; i < 32; i++)
        if (i % 2 == 1)
            *mask ^= (1 << i);
}

void mirrorBits(uint16_t* mask) {
    *mask = ~(*mask);
}

void toBin(unsigned n) {
    unsigned i;

    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}