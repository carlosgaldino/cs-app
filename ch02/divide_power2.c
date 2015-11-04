#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int sign = !!(x & INT_MIN);
    int mask = (1 << k) - 1;
    int bias = (mask + sign) & mask;

    return (x + bias) >> k;
}

int main(int argc, char **argv)
{
    printf("%d\n", divide_power2(2, 0));
    printf("%d\n", divide_power2(2, 1));
    printf("%d\n", divide_power2(6, 1));
    printf("%d\n", divide_power2(6, 2));
    printf("%d\n", divide_power2(8, 2));
    printf("%d\n", divide_power2(128, 3));
    printf("%d\n", divide_power2(35, 2));
}
