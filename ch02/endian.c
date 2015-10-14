#include <stdio.h>

int is_little_endian()
{
    unsigned int x = 1;

    return *(char *) &x;
}

int main(int argc, char **argv)
{
    printf("%d\n", is_little_endian());
    return 0;
}
