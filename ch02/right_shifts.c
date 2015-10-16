#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    int w         = sizeof(unsigned) << 3;
    unsigned mask = ~(0xff << (w - k));

    return xsra & mask;
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl      = (unsigned) x >> k;
    int w         = sizeof(int) << 3;
    unsigned sign = !!((0x1 << (w - 1)) & x);
    unsigned mask = (~sign + 1) << (w - k);

    return xsrl | mask;
}

int main(int argc, char **argv)
{
    printf("%.8x\n", srl(0x1 << 24, 8));
    printf("%.8x\n", srl(~0x0, 6));
    printf("%.8x\n", srl(0x0, 6));

    printf("\n");

    printf("%.8x\n", sra(0x9 << 28, 8));
    printf("%.8x\n", sra(~0x0, 6));
    printf("%.8x\n", sra(0x0, 6));

    return 0;
}
