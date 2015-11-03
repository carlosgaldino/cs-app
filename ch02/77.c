#include <stdio.h>

int multiply(int x, int k)
{
    int result = 0;

    switch (k) {
    case 17:
        result = (x << 4) + x;
        break;
    case -7:
        result = x - (x << 3);
        break;
    case 60:
        result = (x << 6) - (x << 2);
        break;
    case -112:
        result = (x << 4) - (x << 7);
        break;
    }

    return result;
}

int main(int argc, char **argv)
{
    printf("3 x   17 = %4d\n", multiply(3, 17));
    printf("4 x   -7 = %4d\n", multiply(4, -7));
    printf("5 x   60 = %4d\n", multiply(5, 60));
    printf("6 x -112 = %4d\n", multiply(6, -112));
}
