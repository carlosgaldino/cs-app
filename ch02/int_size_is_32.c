#include <stdio.h>

/* A
   The shift must be at most (w-1) bits.
*/

/* B */
int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = (1 << 31) << 1;

    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16()
{
    int set_msb = 1 << 15 << 15;
    int beyond_msb = 1 << 15 << 15 << 2;

    return set_msb && !beyond_msb;
}

int main(int argc, char **argv)
{
    printf("%d\n", int_size_is_32());
    printf("%d\n", int_size_is_32_for_16());
}
