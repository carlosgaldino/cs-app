#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    int w         = sizeof(unsigned) << 3;
    unsigned mask = ~(0xff << (w - k));

    return xsra & mask;
}

int main(int argc, char **argv)
{
    printf("%.8x\n", srl(0x1 << 24, 8));
    printf("%.8x\n", srl(~0x0, 6));
    printf("%.8x\n", srl(0x0, 6));

    return 0;
}
