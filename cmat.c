#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// The main structure that will store the array and the dimension, shape and size of the array
typedef struct ArrStruct
{
    long int *array;
    unsigned int dim;
    unsigned int *shape;
    unsigned int size;
} Array;

// Create a new array of given dimention and shape and return the address of the array structure
// If there is not enough memory then it will return NULL
Array *create_array(unsigned int size)
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
    unsigned int shape[1] = {1};

    array->dim = 1;
    array->shape = shape;
    array->size = size;

    return array;
}

Array *create_array(unsigned int dim, unsigned int size)
{
    unsigned int shape[1] = {size};
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

    array->dim = 1;
    array->shape = shape;
    array->size = size;

    return array;
}

Array *create_array(unsigned int dim, unsigned int *shape)
{
    unsigned int size = sizeof(long int);
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
    array->array = (long int *)malloc(size);
    if (array->array == NULL)
    {
        return NULL;
    }

    array->dim = dim;
    array->shape = shape;
    array->size = size / 8;

    return array;
}

// Create a new zero matrix of given dimensions and shape
// If there is not enough memory then it will return NULL
Array *zeros(unsigned int size)
{
    Array *array = create_array(size);

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 0;
    }

    return array;
}

Array *zeros(unsigned int dim, unsigned int size)
{
    if (size % dim != 0)
    {
        return NULL;
    }

    Array *array = create_array(dim, size);

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

Array *zeros(unsigned int dim, unsigned int *shape)
{
    Array *array = create_array(dim, shape);

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

// Create a new matrix will all values 1 of given dimensions and shape
// If there is not enough memory then it will return NULL
Array *ones(unsigned int size)
{
    Array *array = create_array(size);

    register unsigned int i;
    for (i = 0; i < size; i++)
    {
        *(array->array + i) = 1;
    }

    return array;
}

Array *ones(unsigned int dim, unsigned int size)
{
    Array *array = create_array(dim, size);

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

Array *ones(unsigned int dim, unsigned int *shape)
{
    Array *array = create_array(dim, shape);

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

// Create a new identity matrix of the given size. It will always be a square matrix and
// the dimensions will always 2D
// If there is not enough memory then it will return NULL
Array *identity_matrix(unsigned int size)
{
    unsigned int shape[] = {size, size};
    Array *array = create_array(2, shape);

    if (array == NULL)
    {
        return NULL;
    }

    register unsigned int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            *(array->array + i * size + j) = 0;
        }
    }

    for (i = 0; i < size; i++)
    {
        *(array->array + i * size + i) = 1;
    }

    return array;
}

// Create a new matrix with random values range between the given low and high
// of the given dimension and shape
// If there is not enough memory then it will return NULL
Array *randint(int low, int high, int dim, int *shape)
{
    Array *array = create_array(dim, shape);
    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (long int)rand() % (high - low + 1) + low;
    }

    return array;
}

// Create a new matrix of the given dimension and shape
// If there is not enough memory then it will return NULL
Array *random(int dim, int *shape)
{
    Array *array = create_array(dim, shape);
    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        *(array->array + i) = (long int)rand();
    }

    return array;
}

void show_array(Array *array)
{
    register unsigned int i;

    for (i = 0; i < array->size; i++)
    {
        printf("%d ", *(array->array + i));
    }
    printf("\n");
}

Array *add_value(Array *array, int val)
{
    register unsigned int i;
    Array *new_array = create_array(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) + val;
    }

    return new_array;
}

Array *sub_value(Array *array, int val)
{
    register unsigned int i;
    Array *new_array = create_array(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) - val;
    }

    return new_array;
}

Array *mul_value(Array *array, int val)
{
    register unsigned int i;
    Array *new_array = create_array(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) * val;
    }

    return new_array;
}

Array *div_value(Array *array, int val)
{
    register unsigned int i;
    Array *new_array = create_array(array->dim, array->shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i) / val;
    }

    return new_array;
}

Array *add_array(Array *array1, Array *array2)
{
    if (array1->dim == array2->dim)
    {
        register unsigned int i;
        register unsigned short int flag = 1;

        for (i = 0; i < array1->dim; i++)
        {
            if (*(array1->shape + i) != *(array2->shape + i))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            Array *new_array = create_array(array1->dim, array1->shape);
            for (i = 0; i < array1->size; i++)
            {
                (*(new_array->array + i)) = (*(array1->array + i)) + (*(array2->array + i));
            }
            return new_array;
        }
    }
    return NULL;
}

Array *sub_array(Array *array1, Array *array2)
{
    if (array1->dim == array2->dim)
    {
        register unsigned int i;
        register unsigned short int flag = 1;

        for (i = 0; i < array1->dim; i++)
        {
            if ((*(array1->shape + i)) != (*(array2->shape + i)))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            Array *new_array = create_array(array1->dim, array1->shape);
            for (i = 0; i < array1->size; i++)
            {
                (*(new_array->array + i)) = (*(array1->array + i)) - (*(array2->array + i));
            }
            return new_array;
        }
    }
    return NULL;
}

Array *mul_array(Array *array1, Array *array2)
{
    if (array1->dim == array2->dim)
    {
        register unsigned int i;
        register unsigned short int flag = 1;

        for (i = 0; i < array1->dim; i++)
        {
            if (*(array1->shape + i) != *(array2->shape + i))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            Array *new_array = create_array(array1->dim, array1->shape);
            for (i = 0; i < array1->size; i++)
            {
                (*(new_array->array + i)) = (*(array1->array + i)) * (*(array2->array + i));
            }
            return new_array;
        }
    }
    return NULL;
}

Array *div_array(Array *array1, Array *array2)
{
    if (array1->dim == array2->dim)
    {
        register unsigned int i;
        register unsigned short int flag = 1;

        for (i = 0; i < array1->dim; i++)
        {
            if ((*(array1->shape + i)) != (*(array2->shape + i)))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            Array *new_array = create_array(array1->dim, array1->shape);
            for (i = 0; i < array1->size; i++)
            {
                (*(new_array->array + i)) = (*(array1->array + i)) / (*(array2->array + i));
            }
            return new_array;
        }
    }
    return NULL;
}

Array *array_range(int low, int high, int step)
{
    register int i, j;
    unsigned int shape[1] = {(high - low + 1) / step};
    Array *array = create_array(1, shape);

    for (i = low, j = 0; i < high; i += step, j++)
    {
        *(array->array + j) = i;
    }

    return array;
}

Array *reshape(Array *array, int dim, int *shape)
{
    register unsigned int i, size = 1;
    Array *new_array = create_array(dim, shape);

    for (i = 0; i < dim; i++)
    {
        size *= *(shape + i);
    }

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i);
    }

    if (size == array->size)
    {
        new_array->dim = dim;
        new_array->shape = shape;
    }
    else
    {
        return NULL;
    }

    return new_array;
}

void show_shape(Array *array)
{
    register unsigned int i;
    for (i = 0; i < array->dim; i++)
    {
        printf("%d ", *(array->shape + i));
    }
    printf("\n");
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

int set(Array *array, unsigned int *index, long int val)
{
    unsigned int address = 0;
    register unsigned int i;

    for (i = 0; i < array->dim; i++)
    {
        if (*(array->shape + i) <= *(index + i))
        {
            return 0;
        }
        address += *(index + i) * pow(*(array->shape + i), array->dim - i - 1);
    }

    *(array->array + address) = val;
    return 1;
}

Array *ravel(Array *array)
{
    unsigned int shape[] = {array->size};
    register unsigned int i;

    Array *new_array = create_array(1, shape);

    for (i = 0; i < array->size; i++)
    {
        *(new_array->array + i) = *(array->array + i);
    }

    return new_array;
}

int isany(Array *array, long int val)
{
    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) == val)
        {
            return 1;
        }
    }
    return 0;
}

int isall(Array *array, long int val)
{
    register unsigned int i = 0;
    for (i = 0; i < array->size; i++)
    {
        if (*(array->array + i) != val)
        {
            return 0;
        }
    }
    return 1;
}

int isequal(Array *array1, Array *array2)
{
    if (array1->size == array2->size)
    {
        register unsigned int i;

        for (i = 0; i < array1->size; i++)
        {
            if (*(array1->array + i) != *(array2->array + i))
            {
                return 0;
            }
        }
        return 1;
    }
    return -1;
}

int isequal_dim(Array *array1, Array *array2)
{
    if (array1->dim == array2->dim)
    {
        register unsigned int i;

        for (i = 0; i < array1->dim; i++)
        {
            if (*(array1->shape + 1) != *(array2->shape + 1))
            {
                return 0;
            }
        }
        return 1;
    }
    return -1;
}

Array *combinations(long int *values, unsigned int size, int comb)
{
    Array *array = create_array(2, size);
}

// Array *slice(Array *array, int *slice_indx)
// {
//     if (array->dim != sizeof(slice_indx) / sizeof(slice_indx[0]))
//     {
//         return NULL;
//     }
//     register unsigned int i;
//     register int size;
//     for (i = 0; i < array->dim; i++)
//     {
//         if (*(slice_indx + i) < 0)
//         {
//             size++;
//         }
//     }
//     unsigned int *shape = (unsigned int *)malloc(size * sizeof(unsigned int));
//     for (i = 0; i < array->dim; i++)
//     {
//         if (*(slice_indx + i) < 0)
//         {
//             *(shape + i) = *(array->shape + i);
//         }
//     }
// }