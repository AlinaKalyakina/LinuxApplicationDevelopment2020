#include <stdlib.h>


int main(void)
{
    char *a = malloc(10000);
    free(a);
    free(a);
}

