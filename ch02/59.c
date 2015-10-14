#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned x = 0x89abcdef;
    unsigned y = 0x76543210;

    printf("%.8x\n", ((x & 0xff) | (y & ~0xff)));
    printf("%.8x\n", ((x << 24) >> 24 | (y >> 8) << 8));

    return 0;
}
