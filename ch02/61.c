#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 29;
    unsigned shift = (sizeof(int) - 1) << 3; /* shift by w - 8 */

    /* A */
    printf("%d\n", !!(x & ~0x00));
    printf("%d\n", !!(x | 0x00));

    printf("%d\n", !!(0 & ~0x00));
    printf("%d\n", !!(0 | 0x00));

    /* B */
    printf("%d\n", !!(x ^ ~0x00));
    printf("%d\n", !!((0xff << shift >> shift) ^ ~0x00));

    /* C */
    printf("%d\n", !!(((x | 0x00) << shift) >> shift));
    x = 0x1200;
    printf("%d\n", !!(((x | 0x00) << shift) >> shift));

    /* D */
    printf("%d\n", !!((x ^ ~0x00) & (0xff << shift)));
    x = (0xff << shift) >> 1;
    printf("%d\n", !!((x ^ ~0x00) & (0xff << shift)));

    return 0;
}
