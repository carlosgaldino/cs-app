#include <stdio.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF & frac != 0) /* NaN */
        return f;

    return f & 0x7FFFFFFF;
}

int main(int argc, char **argv)
{
    printf("%.8X\n", 0x12345678);
    printf("%.8X\n", float_absval(0x92345678));
    printf("%.8X\n", float_absval(0xFF945678));
}
