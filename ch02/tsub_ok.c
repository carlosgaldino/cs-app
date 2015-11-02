#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y)
{
    int sub = x - y;
    int pos_overflow = !(x & INT_MIN) &&  (y & INT_MIN) &&  (sub & INT_MIN);
    int neg_overflow =  (x & INT_MIN) && !(y & INT_MIN) && !(sub & INT_MIN);

    return !(pos_overflow || neg_overflow);
}

int main(int argc, char **argv)
{
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    printf("%d\n", tsub_ok(10, 10));
    printf("%d\n", tsub_ok(INT_MAX, 10));
    printf("%d\n", tsub_ok(INT_MAX, 0));
    printf("%d\n", tsub_ok(INT_MIN, 10));
    printf("%d\n", tsub_ok(INT_MIN, -2));
}
