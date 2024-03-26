#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 30;
    int *pAge = &age; /* simple pointer data type */
    int **ppAge = &pAge; /* pointer to pointer */

    printf("%p\n", pAge); /* printing the memory address of the age variable*/
    printf("%d\n", *pAge); /* dereferencing the pAge pointer(getting the value stored there) */
    printf("%p\n", **ppAge); /* getting the memory address stored in the pAge pointer */

    printf("%d", *&age); /*dereferencing the pointer to age*/

    return 0;
}
