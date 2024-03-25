#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 5;
    printf("%d\n", num);
    num = 8;
    printf("%d", num);

    /* Const can't be modified*/

    const int NUM2 = 5;

    return 0;
}
