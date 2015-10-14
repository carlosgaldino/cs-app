#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned char *c = &x;

    *(c + i) = b;

    return x;
}

unsigned rreplace_byte(unsigned x, int i, unsigned char b)
{
    return (x & ~(0xff << i * 8)) | (b << i * 8);
}

int main(int argc, char **argv)
{
    printf("%.8x\n", replace_byte(0x12345678, 2, 0xab));
    printf("%.8x\n", replace_byte(0x12345678, 0, 0xab));
    printf("%.8x\n", replace_byte(0x12345678, 3, 0xab));
    printf("%.8x\n", replace_byte(0x12345678, 1, 0xab));

    printf("\n");

    printf("%.8x\n", rreplace_byte(0x12345678, 2, 0xab));
    printf("%.8x\n", rreplace_byte(0x12345678, 0, 0xab));
    printf("%.8x\n", rreplace_byte(0x12345678, 3, 0xab));
    printf("%.8x\n", rreplace_byte(0x12345678, 1, 0xab));

    return 0;
}
