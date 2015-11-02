#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A
 * `size_of` returns an `unsigned`. Then the condition will always be greater than 0.
 */

void copy_int(int val, void *buf, int maxbytes)
{
    if ((maxbytes - (int) sizeof(val)) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

int main(int argc, char **argv)
{
    int *buf = malloc(sizeof(int));

    copy_int(10, buf, 10);
    printf("%d\n", *buf);

    copy_int(30, buf, 1);
    printf("%d\n", *buf);

    copy_int(30, buf, 4);
    printf("%d\n", *buf);

    free(buf);
}
