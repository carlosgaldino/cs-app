#include <stdio.h>

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assuming w=32 */
int any_odd_one(unsigned x)
{
    unsigned mask = 0xaaaaaaaa;

    return !!(x & mask);
}

int main(int argc, char **argv)
{
    printf("%d\n", any_odd_one(0x1));
    printf("%d\n", any_odd_one(0x2));
    printf("%d\n", any_odd_one(0x33333333));
    printf("%d\n", any_odd_one(0x55555555));

    return 0;
}
