#include <stdio.h>

/*
 * Mask with least significant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n)
{
    int move_bits_mask = (n == sizeof(int) << 3) - 1;
    int mask = ~(move_bits_mask << n);
    return mask;
}

int main(int argc, char **argv)
{
    printf("%.8x\n", lower_one_mask(6));
    printf("%.8x\n", lower_one_mask(17));
    printf("%.8x\n", lower_one_mask(32));
}
