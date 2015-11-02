#include <stdio.h>
#include <limits.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{
    int sum = x + y;
    int pos_overflow = !(x & INT_MIN) && !(y & INT_MIN) &&  (sum & INT_MIN);
    int neg_overflow =  (x & INT_MIN) &&  (y & INT_MIN) && !(sum & INT_MIN);

    (!pos_overflow || (sum = INT_MAX)) && (!neg_overflow || (sum = INT_MIN));

    return sum;
}

int main(int argc, char **argv)
{
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    printf("%d\n", saturating_add(10, 10));
    printf("%d\n", saturating_add(INT_MAX, 10));
    printf("%d\n", saturating_add(INT_MAX, 0));
    printf("%d\n", saturating_add(INT_MIN, 10));
    printf("%d\n", saturating_add(INT_MIN, -2));
}
