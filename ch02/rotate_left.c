#include <stdio.h>

/*
 * Do rotating left shift. Assume 0 <= n < w
 * Examples when x = 0x12345678 and w = 32:
 *   n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(unsigned) << 3;
    unsigned msb = x >> (w-n);
    unsigned new_msb = x << n;

    return new_msb | msb;
}

int main(int argc, char **argv)
{
    printf("%.8x\n", rotate_left(0x12345678, 4));
    printf("%.8x\n", rotate_left(0x12345678, 20));
    printf("%.8x\n", rotate_left(0x12345678, 0));
}
