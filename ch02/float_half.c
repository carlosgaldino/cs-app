#include <stdio.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    switch (exp) {
    case 1:
        if (frac != 0x7FFFFF)
            exp = 0;
        frac |= 0x800000;
    case 0:
        if ((frac & 3) == 3)
            frac += 1;
        frac >>= 1;
        frac &= 0x7FFFFF;
        break;
    case 0xFF:
        break;
    default:
        exp -= 1;
        break;
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char **argv)
{
    printf("%.8X\n", 0x12345678);
    printf("%.8X\n", float_half(0x12345678));
    printf("%.8X\n", float_half(0xFF945678));
}
