#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int tmult_ok(size_t n, size_t m)
{
    size_t p = n * m;

    return !n || p/n == m;
}

void *calloc(size_t nmemb, size_t size)
{
    if (!nmemb || !size)
        return NULL;

    if (!tmult_ok(nmemb, size)) /* Overflow */
        return NULL;

    size_t n = nmemb * size;

    void *ptr = malloc(n);

    if (ptr != NULL)
        memset(ptr, '\0', n);

    return ptr;
}

int main(int argc, char **argv)
{
    printf("%p\n", calloc(SIZE_MAX, SIZE_MAX));
    printf("%p\n", calloc(0, SIZE_MAX));
    printf("%p\n", calloc(SIZE_MAX, 0));
    printf("%p\n", calloc(0, 0));
    printf("%p\n", calloc(20, 30));
}
