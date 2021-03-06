#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct ArrStruct
{
    long int *array;
    unsigned int dim;
    unsigned int *shape;
    unsigned int size;
} Array;

typedef struct ArrStruct_bool
{
    bool *array;
    unsigned int dim;
    unsigned int *shape;
    unsigned int size;
} ArrayBool;

typedef struct ArrStruct_float
{
    double *array;
    unsigned int dim;
    unsigned int *shape;
    unsigned int size;
} ArrayFloat;

bool isany(Array *array, long int val);
bool isany_b(ArrayBool *array, bool val);
bool isany_f(ArrayFloat *array, double val);

bool isall(Array *array, long int val);
bool isall_b(ArrayBool *array, bool val);
bool isall_f(ArrayFloat *array, double val);

bool isequal(Array *array1, Array *array2);
bool isequal_b(ArrayBool *array1, ArrayBool *array2);
bool isequal_f(ArrayFloat *array1, ArrayFloat *array2);

bool isequal_shape(Array *array1, Array *array2);
bool isequal_shape_b(ArrayBool *array1, ArrayBool *array2);
bool isequal_shape_f(ArrayFloat *array1, ArrayFloat *array2);

Array *array_with_size(unsigned int size)
{
    Array *array = (Array *)malloc(sizeof(Array));
    if (array == NULL)
    {
        return NULL;
    }

    array->array = (long int *)malloc(size * sizeof(long int));
    if (array->array == NULL)
    {
        return NULL;
    }
    unsigned int *shape = (unsigned int *)malloc(sizeof(unsigned int));
    *shape = size;

    array->dim = 1;
    array->shape = shape;
    array->size = size;

    return array;
}

ArrayBool *array_with_size_b(unsigned int size)
{
    ArrayBool *array = (ArrayBool *)malloc(sizeof(ArrayBool));
    if (array == NULL)
    {
        return NULL;
    }

    array->array = (bool *)malloc(size * sizeof(bool));
    if (array->array == NULL)
    {
        return NULL;
    }
    unsigned int *shape = (unsigned int *)malloc(sizeof(unsigned int));
    *shape = size;

    array->dim = 1;
    array->shape = shape;
    array->size = size;

    return array;
}

ArrayFloat *array_with_size_f(unsigned int size)
{
    ArrayFloat *array = (ArrayFloat *)malloc(sizeof(ArrayFloat));
    if (array == NULL)
    {
        return NULL;
    }

    array->array = (double *)malloc(size * sizeof(double));
    if (array->array == NULL)
    {
        return NULL;
    }
    unsigned int *shape = (unsigned int *)malloc(sizeof(unsigned int));
    *shape = size;

    array->dim = 1;
    array->shape = shape;
    array->size = size;

    return array;
}

Array *array_with_dim_shape(unsigned int dim, unsigned int *shape)
{
    unsigned int size = 1;
    register unsigned int i;

    for (i = 0; i < dim; i++)
    {
        size *= *(shape + i);
    }

    Array *array = (Array *)malloc(sizeof(Array));
    if (array == NULL)
    {
        return NULL;
    }
    array->array = (long int *)malloc(size * sizeof(long int));
    if (array->array == NULL)
    {
        return NULL;
    }

    array->dim = dim;
    array->shape = shape;
    array->size = size;

    return array;
}

ArrayBool *array_with_dim_shape_b(unsigned int dim, unsigned int *shape)
{
    unsigned int size = 1;
    register unsigned int i;

    for (i = 0; i < dim; i++)
    {
        size *= *(shape + i);
    }

    ArrayBool *array = (ArrayBool *)malloc(sizeof(ArrayBool));
    if (array == NULL)
    {
        return NULL;
    }
    array->array = (bool *)malloc(size * sizeof(bool));
    if (array->array == NULL)
    {
        return NULL;
    }

    array->dim = dim;
    array->shape = shape;
    array->size = size;

    return array;
}

ArrayFloat *array_with_dim_shape_f(unsigned int dim, unsigned int *shape)
{
    unsigned int size = 1;
    register unsigned int i;

    for (i = 0; i < dim; i++)
    {
        size *= *(shape + i);
    }

    ArrayFloat *array = (ArrayFloat *)malloc(sizeof(ArrayFloat));
    if (array == NULL)
    {
        return NULL;
    }
    array->array = (double *)malloc(size * sizeof(double));
    if (array->array == NULL)
    {
        return NULL;
    }

    array->dim = dim;
    array->shape = shape;
    array->size = size;

    return array;
}

Array *zeros_with_size(unsigned int size)
{
    Array *array = array_with_size(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

ArrayBool *zeros_with_size_b(unsigned int size)
{
    ArrayBool *array = array_with_size_b(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

ArrayFloat *zeros_with_size_f(unsigned int size)
{
    ArrayFloat *array = array_with_size_f(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

Array *zeros_with_dim_shape(unsigned int dim, unsigned int *shape)
{
    Array *array = array_with_dim_shape(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

ArrayBool *zeros_with_dim_shape_b(unsigned int dim, unsigned int *shape)
{
    ArrayBool *array = array_with_dim_shape_b(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

ArrayFloat *zeros_with_dim_shape_f(unsigned int dim, unsigned int *shape)
{
    ArrayFloat *array = array_with_dim_shape_f(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

Array *ones_with_size(unsigned int size)
{
    Array *array = array_with_size(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

ArrayBool *ones_with_size_b(unsigned int size)
{
    ArrayBool *array = array_with_size_b(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

ArrayFloat *ones_with_size_f(unsigned int size)
{
    ArrayFloat *array = array_with_size_f(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

Array *ones_with_dim_shape(unsigned int dim, unsigned int *shape)
{
    Array *array = array_with_dim_shape(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

ArrayBool *ones_with_dim_shape_b(unsigned int dim, unsigned int *shape)
{
    ArrayBool *array = array_with_dim_shape_b(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

ArrayFloat *ones_with_dim_shape_f(unsigned int dim, unsigned int *shape)
{
    ArrayFloat *array = array_with_dim_shape_f(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

Array *identity_matrix(unsigned int size)
{
    unsigned int shape[] = {size, size};
    Array *array = array_with_dim_shape(2, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
            {
                *(array->array + i * size + i) = 1;
            }
            else
            {
                *(array->array + i * size + j) = 0;
            }
        }
    }

    return array;
}

ArrayBool *identity_matrix_b(unsigned int size)
{
    unsigned int shape[] = {size, size};
    ArrayBool *array = array_with_dim_shape_b(2, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
            {
                *(array->array + i * size + i) = 1;
            }
            else
            {
                *(array->array + i * size + j) = 0;
            }
        }
    }

    return array;
}

ArrayFloat *identity_matrix_f(unsigned int size)
{
    unsigned int shape[] = {size, size};
    ArrayFloat *array = array_with_dim_shape_f(2, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
            {
                *(array->array + i * size + i) = 1;
            }
            else
            {
                *(array->array + i * size + j) = 0;
            }
        }
    }

    return array;
}

Array *randint_with_size(int low, int high, unsigned int size)
{
    Array *array = array_with_size(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (long int)rand() % (high - low + 1) + low;
    }

    return array;
}

Array *randint_with_dim_shape(int low, int high, unsigned int dim, unsigned int *shape)
{
    Array *array = array_with_dim_shape(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (long int)rand() % (high - low + 1) + low;
    }

    return array;
}

Array *random_with_size(unsigned int size)
{
    Array *array = array_with_size(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (long int)rand();
    }

    return array;
}

ArrayBool *random_with_size_b(unsigned int size)
{
    ArrayBool *array = array_with_size_b(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (bool)((int)rand() % 2);
    }

    return array;
}

ArrayFloat *random_with_size_f(unsigned int size)
{
    ArrayFloat *array = array_with_size_f(size);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (double)rand();
    }

    return array;
}

Array *random_with_dim_shape(unsigned int dim, unsigned int *shape)
{
    Array *array = array_with_dim_shape(dim, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (long int)rand();
    }

    return array;
}

void show_array(Array *array)
{
    if (array != NULL)
    {
        register unsigned int i;

        for (i = 0; i < array->size; i++)
        {
            printf("%ld ", *(array->array + i));
        }
        printf("\n");
    }
}

Array *add_value(Array *array, int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    Array *new_array = array_with_dim_shape(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) + val;
    }

    return new_array;
}

bool add_value_inplace(Array *array, int val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = *(array->array + i) + val;
    }

    return true;
}

Array *sub_value(Array *array, int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    Array *new_array = array_with_dim_shape(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) - val;
    }

    return new_array;
}

bool sub_value_inplace(Array *array, int val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = *(array->array + i) - val;
    }

    return true;
}

Array *mul_value(Array *array, int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    Array *new_array = array_with_dim_shape(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) * val;
    }

    return new_array;
}

bool mul_value_inplace(Array *array, int val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = *(array->array + i) * val;
    }

    return true;
}

Array *div_value(Array *array, int val)
{
    if (array == NULL || val == 0)
    {
        return NULL;
    }

    register unsigned int i;
    Array *new_array = array_with_dim_shape(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) / val;
    }

    return new_array;
}

bool div_value_inplace(Array *array, int val)
{
    if (array == NULL)
    {
        return false;
    }
    else if (val == 0)
    {
        return false;
    }

    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = *(array->array + i) / val;
    }

    return true;
}

Array *add_array(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL || array1->dim != array2->dim)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return NULL;
        }
    }

    Array *new_array = array_with_dim_shape(array1->dim, array1->shape);

    if (new_array == NULL)
    {
        return NULL;
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(new_array->array + i)) = (*(array1->array + i)) + (*(array2->array + i));
    }
    return new_array;
}

bool add_array_inplace(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }
    else if (array1->dim != array2->dim)
    {
        return false;
    }

    register unsigned int i;
    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return false;
        }
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(array1->array + i)) = (*(array1->array + i)) + (*(array2->array + i));
    }
    return true;
}

Array *sub_array(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL || array1->dim != array2->dim)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return NULL;
        }
    }

    Array *new_array = array_with_dim_shape(array1->dim, array1->shape);

    if (new_array == NULL)
    {
        return NULL;
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(new_array->array + i)) = (*(array1->array + i)) - (*(array2->array + i));
    }
    return new_array;
}

bool sub_array_inplace(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }
    else if (array1->dim != array2->dim)
    {
        return false;
    }

    register unsigned int i;
    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return false;
        }
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(array1->array + i)) = (*(array1->array + i)) - (*(array2->array + i));
    }
    return true;
}

Array *mul_array(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL || array1->dim != array2->dim)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return NULL;
        }
    }

    Array *new_array = array_with_dim_shape(array1->dim, array1->shape);

    if (new_array == NULL)
    {
        return NULL;
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(new_array->array + i)) = (*(array1->array + i)) * (*(array2->array + i));
    }
    return new_array;
}

int mul_array_inplace(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return -99;
    }
    else if (array1->dim != array2->dim)
    {
        return 0;
    }

    register unsigned int i;
    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return 0;
        }
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(array1->array + i)) = (*(array1->array + i)) * (*(array2->array + i));
    }
    return 1;
}

Array *div_array(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL || array1->dim != array2->dim)
    {
        return NULL;
    }

    register unsigned int i;

    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return NULL;
        }
    }

    Array *new_array = array_with_dim_shape(array1->dim, array1->shape);

    if (new_array == NULL)
    {
        return NULL;
    }

    for (i = 0; i < array1->size; i++)
    {
        if (*(array2->array + i) == 0)
        {
            return NULL;
        }

        (*(new_array->array + i)) = (*(array1->array + i)) / (*(array2->array + i));
    }
    return new_array;
}

int div_array_inplace(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return -99;
    }
    else if (array1->dim != array2->dim)
    {
        return 0;
    }

    register unsigned int i;
    for (i = 0; i < array1->dim; i++)
    {
        if (*(array1->shape + i) != *(array2->shape + i))
        {
            return 0;
        }
    }

    if (isany(array2, 0))
    {
        return 0;
    }

    for (i = 0; i < array1->size; i++)
    {
        (*(array1->array + i)) = (*(array1->array + i)) / (*(array2->array + i));
    }
    return 1;
}

Array *array_range(int low, int high, int step)
{
    register int i, j;
    unsigned int shape[1] = {(high - low + 1) / step};
    Array *array = array_with_dim_shape(1, shape);

    if (array == NULL)
    {
        return NULL;
    }

    for (i = low, j = 0; i < high; i += step, j++)
    {
        *(array->array + j) = i;
    }

    return array;
}

Array *reshape(Array *array, int dim, int *shape)
{
    register unsigned int i, size = 1;
    Array *new_array = array_with_dim_shape(dim, shape);

    if (array == NULL || new_array == NULL)
    {
        return NULL;
    }

    for (i = 0; i < dim; i++)
    {
        size *= *(shape + i);
    }

    if (size == array->size)
    {
        new_array->dim = dim;
        new_array->shape = shape;

        for (i = 0; i < array->size; i++)
        {
            *(new_array->array + i) = *(array->array + i);
        }
    }
    else
    {
        return NULL;
    }

    return new_array;
}

int reshape_inplace(Array *array, int dim, int *shape)
{
    register unsigned int i, size = 1;

    if (array == NULL)
    {
        return -99;
    }

    for (i = 0; i < dim; i++)
    {
        size *= *(shape + i);
    }

    if (size == array->size)
    {
        array->dim = dim;
        array->shape = shape;
    }
    else
    {
        return 0;
    }

    return 1;
}

void show_shape(Array *array)
{
    if (array != NULL)
    {
        register unsigned int i;
        for (i = 0; i < array->dim; i++)
        {
            printf("%d ", *(array->shape + i));
        }
        printf("\n");
    }
}

long int get(Array *array, unsigned int *index)
{
    unsigned int address = 0;
    register unsigned int i;

    for (i = 0; i < array->dim; i++)
    {
        if (*(array->shape + i) <= *(index + i))
        {
            *(index + i) = *(array->shape + i) - 1;
        }
        address += *(index + i) * pow(*(array->shape + i), array->dim - i - 1);
    }

    return *(array->array + address);
}

Array *set(Array *array, unsigned int *index, long int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    Array *new_array = array_with_dim_shape(array->dim, array->shape);
    register unsigned int i;

    if (new_array == NULL)
    {
        return NULL;
    }
    else
    {
        for (i = 0; i < array->size; i++)
        {
            *(new_array->array + i) = *(array->array + i);
        }
    }

    unsigned int address = 0;
    for (i = 0; i < array->dim; i++)
    {
        if (*(new_array->shape + i) <= *(index + i))
        {
            return NULL;
        }
        address += *(index + i) * pow(*(new_array->shape + i), new_array->dim - i - 1);
    }

    *(new_array->array + address) = val;
    return new_array;
}

bool set_inplace(Array *array, unsigned int *index, long int val)
{
    if (array == NULL)
    {
        return false;
    }

    unsigned int address = 0;
    register unsigned int i;

    for (i = 0; i < array->dim; i++)
    {
        if (*(array->shape + i) <= *(index + i))
        {
            return false;
        }
        address += *(index + i) * pow(*(array->shape + i), array->dim - i - 1);
    }

    *(array->array + address) = val;
    return true;
}

Array *ravel(Array *array)
{
    if (array == NULL)
    {
        return NULL;
    }

    unsigned int shape[] = {array->size};
    register unsigned int i;

    Array *new_array = array_with_dim_shape(1, shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i);
    }

    return new_array;
}

bool isany(Array *array, long int val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) == val)
        {
            return true;
        }
    }
    return false;
}

bool isanyb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) == val)
        {
            return true;
        }
    }
    return false;
}

bool isanyf(ArrayFloat *array, double val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) == val)
        {
            return true;
        }
    }
    return false;
}

bool isall(Array *array, long int val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) != val)
        {
            return false;
        }
    }
    return true;
}

bool isallb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) != val)
        {
            return false;
        }
    }
    return true;
}

bool isallf(ArrayFloat *array, double val)
{
    if (array == NULL)
    {
        return false;
    }

    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) != val)
        {
            return false;
        }
    }
    return true;
}

bool isequal(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }

    if (array1->size == array2->size)
    {
        register unsigned int i;

        for (i = 0; i < array1->size; i++)
        {
            if (*(array1->array + i) != *(array2->array + i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isequalb(ArrayBool *array1, ArrayBool *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }

    if (array1->size == array2->size)
    {
        register unsigned int i;

        for (i = 0; i < array1->size; i++)
        {
            if (*(array1->array + i) != *(array2->array + i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isequalf(ArrayFloat *array1, ArrayFloat *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }

    if (array1->size == array2->size)
    {
        register unsigned int i;

        for (i = 0; i < array1->size; i++)
        {
            if (*(array1->array + i) != *(array2->array + i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isequal_shape(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }

    if (array1->dim == array2->dim)
    {
        register unsigned int i;

        for (i = 0; i < array1->dim; i++)
        {
            if (*(array1->shape + 1) != *(array2->shape + 1))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isequal_shape_b(ArrayBool *array1, ArrayBool *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }

    if (array1->dim == array2->dim)
    {
        register unsigned int i;

        for (i = 0; i < array1->dim; i++)
        {
            if (*(array1->shape + 1) != *(array2->shape + 1))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isequal_shape_f(ArrayFloat *array1, ArrayFloat *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }

    if (array1->dim == array2->dim)
    {
        register unsigned int i;

        for (i = 0; i < array1->dim; i++)
        {
            if (*(array1->shape + 1) != *(array2->shape + 1))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool copy_array(Array *array1, Array *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }
    if (array1->dim == array2->dim && isequal_shape(array1, array2))
    {
        register unsigned int i;
        for (i = 0; i < array1->size; i++)
        {
            *(array2->array + i) = *(array1->array + i);
        }
        return true;
    }
    return false;
}

bool copy_array_b(ArrayBool *array1, ArrayBool *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }
    if (array1->dim == array2->dim && isequal_shape_b(array1, array2))
    {
        register unsigned int i;
        for (i = 0; i < array1->size; i++)
        {
            *(array2->array + i) = *(array1->array + i);
        }
        return true;
    }
    return false;
}

bool copy_array_f(ArrayFloat *array1, ArrayFloat *array2)
{
    if (array1 == NULL || array2 == NULL)
    {
        return false;
    }
    if (array1->dim == array2->dim && isequal_shape_f(array1, array2))
    {
        register unsigned int i;
        for (i = 0; i < array1->size; i++)
        {
            *(array2->array + i) = *(array1->array + i);
        }
        return true;
    }
    return false;
}

Array *create_copy(Array *array)
{
    if (array == NULL)
    {
        return NULL;
    }

    Array *new_array = array_with_dim_shape(array->dim, array->shape);
    if (copy_array(array, new_array) == true)
    {
        return new_array;
    }
    return NULL;
}

ArrayBool *create_copyb(ArrayBool *array)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (copy_array_b(array, new_array) == true)
    {
        return new_array;
    }
    return NULL;
}

ArrayFloat *create_copyf(ArrayFloat *array)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayFloat *new_array = array_with_dim_shape_f(array->dim, array->shape);
    if (copy_array_f(array, new_array) == true)
    {
        return new_array;
    }
    return NULL;
}

ArrayBool *where_val_eq(Array *array, long int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) == val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_eqb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) == val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_eqf(ArrayFloat *array, double val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (abs(*(array->array + i) - val) < 0.00001) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_ls(Array *array, long int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) < val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_lsb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) < val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_lsf(ArrayFloat *array, double val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) < val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_gt(Array *array, long int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) > val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_gtb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) > val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_gtf(ArrayFloat *array, float val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) > val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_le(Array *array, long int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) <= val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_leb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) <= val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_lef(ArrayFloat *array, double val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) <= val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_ge(Array *array, long int val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) >= val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_geb(ArrayBool *array, bool val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) >= val) ? true : false;
    }

    return new_array;
}

ArrayBool *where_val_gef(ArrayFloat *array, double val)
{
    if (array == NULL)
    {
        return NULL;
    }

    ArrayBool *new_array = array_with_dim_shape_b(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i) >= val) ? true : false;
    }

    return new_array;
}

Array *array_not(Array *array)
{
    Array *new_array = array_with_dim_shape(array->dim, array->shape);
    if (new_array == NULL)
    {
        return NULL;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = (*(array->array + i)) ? 0 : 1;
    }

    return new_array;
}

int array_not_inplace(Array *array)
{
    if (array == NULL)
    {
        return -99;
    }

    register unsigned int i;
    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (*(array->array + i)) ? 0 : 1;
    }

    return 1;
}

Array *array_indexing(Array *array, Array *index_array)
{
    if (array == NULL || index_array == NULL)
    {
        return NULL;
    }

    if (array->dim == index_array->dim && isequal_shape(array, index_array))
    {
        register unsigned int i, size = 0;
        for (i = 0; i < array->size; i++)
        {
            if (*(index_array->array + i))
            {
                size++;
            }
        }

        Array *new_array = array_with_size(size);

        for (i = 0; i < array->size; i++)
        {
            if (*(index_array->array + i))
            {
                *(new_array->array + i) = *(array->array + i);
            }
        }
        return new_array;
    }
    return NULL;
}

Array *array_AND(Array *array1, Array *array2)
{
    if (array1->size == array2->size && array1->dim == array2->dim)
    {
        register int i;
        Array *new_array = array_with_dim_shape(array1->dim, array1->shape);

        if (new_array == NULL)
        {
            return NULL;
        }

        for (i = 0; i < array1->size; i++)
        {
            *(new_array->array + i) = *(array1->array + i) && *(array2->array);
        }

        return new_array;
    }

    return NULL;
}

Array *array_OR(Array *array1, Array *array2)
{
    if (array1->size == array2->size && array1->dim == array2->dim)
    {
        register int i;
        Array *new_array = array_with_dim_shape(array1->dim, array1->shape);

        if (new_array == NULL)
        {
            return NULL;
        }

        for (i = 0; i < array1->size; i++)
        {
            *(new_array->array + i) = *(array1->array + i) || *(array2->array);
        }

        return new_array;
    }

    return NULL;
}

double mean(Array *array)
{
    register unsigned int i;
    register double total = 0, count = 0.0;

    for (i = 0; i < array->size; i++)
    {
        count += 1.0;
        total += (double)(*(array->array + i));
    }

    return (double)(total / count);
}
