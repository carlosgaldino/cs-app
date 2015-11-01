#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
   Assume w=32 */
int odd_ones(unsigned x)
{
    /* Use xor as binary addition. Result is 0 if even 1s; 1 otherwise. */
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return (x & 0x1);
}

int main(int argc, char **argv)
{
    printf("%d\n", odd_ones(1));
    printf("%d\n", odd_ones(10));
}
