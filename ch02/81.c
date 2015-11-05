#include <stdio.h>

/* A. 1^(w - k)0^k */
unsigned klowest_zero(unsigned k)
{
    return ~0x0 << k;
}

/* B. 0^(w - k - j)1^k0^j */
unsigned kones_jzeroes(unsigned k, unsigned j)
{
    return (1 << (k + j)) - (1 << j);
}

int main(int argc, char **argv)
{
    printf("%.8x\n", klowest_zero(1));
    printf("%.8x\n", klowest_zero(8));
    printf("%.8x\n", klowest_zero(31));
    printf("%.8x\n", klowest_zero(27));

    printf("%.8x\n", kones_jzeroes(1, 2));
    printf("%.8x\n", kones_jzeroes(8, 3));
    printf("%.8x\n", kones_jzeroes(30, 1));
    printf("%.8x\n", kones_jzeroes(27, 2));
}
