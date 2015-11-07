#include <stdio.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF & frac != 0) /* NaN */
        return f;
    switch (exp) {
    case 0:
        frac <<= 1;
        if (frac & 0x80000000)
            exp = 1;
        frac &= 0x7FFFFF;
        break;
    case 0xFE:
        exp = 0xFF;
        frac = 0;
        break;
    case 0xFF:
        break;
    default:
        exp += 1;
        break;
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char **argv)
{
    printf("%.8X\n", 0x12345678);
    printf("%.8X\n", float_twice(0x12345678));
    printf("%.8X\n", float_twice(0xFF945678));
}
