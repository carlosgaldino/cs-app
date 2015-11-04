#include <stdio.h>
#include <limits.h>

int mul3div4(int x)
{
    int k    = 2;
    int mul  = (x << 1) + x;
    int sign = !!(mul & INT_MIN);
    int mask = (1 << k) - 1;
    int bias = (mask + sign) & mask;

    return (mul + bias) >> k;
}

int main(int argc, char **argv)
{
    printf("%d\n", mul3div4(2));
    printf("%d\n", mul3div4(3));
    printf("%d\n", mul3div4(6));
    printf("%d\n", mul3div4(8));
    printf("%d\n", mul3div4(24));
}
