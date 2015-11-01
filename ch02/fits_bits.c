#include <stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int mask = (unsigned) -1 >> (w-n);

    return (x & mask) == x;
}

int main(int argc, char **argv)
{
    printf("%d\n", fits_bits(350, 8));
    printf("%d\n", fits_bits(350, 16));
}
