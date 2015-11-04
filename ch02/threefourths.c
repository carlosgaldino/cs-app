#include <stdio.h>
#include <limits.h>

int threefourths(int x)
{
    int sign = x & INT_MIN;

    int tail = ((x & 1) << 1) + (x & 3);
    int base = (x >> 1) + (x >> 2);
    int bias = (tail >> 2) + (sign && (tail & 3));

    return base + bias;
}

int main(int argc, char **argv)
{
    printf("%d\n", threefourths(4));
    printf("%d\n", threefourths(3));
    printf("%d\n", threefourths(8));
    printf("%d\n", threefourths(9));
}
