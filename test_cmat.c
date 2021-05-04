#include <stdio.h>
#include "cmat.c"

void check_array_with_size()
{
    Array *arr = array_with_size(5);
    ArrayBool *arr_b = array_with_size_b(5);
    ArrayFloat *arr_f = array_with_size_f(5);

    if (arr->dim != 1)
        printf("1. array with wrong dimention\n");
    if (arr->size != 5)
        printf("2. array with wrong size\n");
    if (arr->shape[0] != 5)
        printf("3. array with wrong shape\n");
    if (sizeof(arr->array) / sizeof(arr->array) != 5)
        printf("4. memory allocation error\n");

    if (arr_b->dim != 1)
        printf("5. array with wrong dimention\n");
    if (arr_b->size != 5)
        printf("6. array with wrong size\n");
    if (arr_b->shape[0] != 5)
        printf("7. array with wrong shape\n");
    if (sizeof(arr_b->array) / sizeof(arr_b->array[0]) != 5)
        printf("8. memory allocation error\n");

    if (arr_f->dim != 1)
        printf("9. array with wrong dimention\n");
    if (arr_f->size != 5)
        printf("10. array with wrong size\n");
    if (arr_f->shape[0] != 5)
        printf("11. array with wrong shape\n");
    if (sizeof(arr_f->array) / sizeof(arr_f->array[0]) != 5)
        printf("12. memory allocation error\n");
}

int main()
{
    printf("1. Check array with size\n----------\n");
    check_array_with_size();

    return 0;
}