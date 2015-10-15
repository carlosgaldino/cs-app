#include <stdio.h>

int int_shifts_are_arithmetic()
{
    return !!((-1 >> 1) & ~0x0);
}

int main(int argc, char **argv)
{
    printf("%d\n", int_shifts_are_arithmetic());

    return 0;
}
