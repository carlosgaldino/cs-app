#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF & frac != 0) /* NaN */
        return f;

    return (~sign << 31) | (f & 0x7FFFFFFF);
}

int main(int argc, char **argv)
{
    printf("%.8X\n", 0x12345678);
    printf("%.8X\n", float_negate(0x12345678));
    printf("%.8X\n", float_negate(0xFF945678));
}
