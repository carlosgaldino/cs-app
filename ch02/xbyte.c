#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
   into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum)
{
    int qty = (3 - bytenum) << 3;
    return ((int) word << qty) >> 24;
}

int main(int argc, char **argv)
{
    printf("%d\n", xbyte(0x80000000, 3));
    printf("%d\n", xbyte(0x00800000, 2));
    printf("%d\n", xbyte(0x00008000, 1));
    printf("%d\n", xbyte(0xF0008070, 0));
    printf("%d\n", xbyte(0xFF008000, 3));
}
