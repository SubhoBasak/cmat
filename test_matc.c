#include "cmat.c"

void main()
{
    unsigned int shape1[] = {2, 2, 2};
    unsigned int shape2[] = {4, 4};
    unsigned int shape3[] = {2, 4};

    Array *array1 = create_array(3, shape1);
    Array *array2 = ones(2, shape2);
    Array *array3 = zeros(2, shape2);
    Array *array4 = identity_matrix(5);
    Array *array5 = add_value(array2, 5);
    Array *array6 = sub_value(array2, 3);
    Array *array7 = mul_value(array2, 5);
    Array *array8 = div_value(array2, 2);
    Array *array9 = add_array(array2, array2);
    Array *array10 = sub_array(array2, array2);
    Array *array11 = mul_array(array2, array2);
    Array *array12 = div_array(array2, array2);
    Array *array13 = randint(3, 7, 3, shape1);
    Array *array14 = random(3, shape1);
    Array *array15 = ones(3, shape1);
    Array *array16 = array_range(-8, 8, 2);

    show_array(array1);
    show_array(array2);
    show_array(array3);
    show_array(array4);
    show_array(array5);
    show_array(array6);
    show_array(array7);
    show_array(array8);
    show_array(array9);
    show_array(array10);
    show_array(array11);
    show_array(array12);
    show_array(array13);
    show_array(array14);

    show_shape(array15);
    Array *reshaped_array = reshape(array15, 2, shape3);
    show_shape(reshaped_array);

    show_array(array16);

    unsigned int indx[] = {1, 0, 1};
    printf("%d\n", get(array1, indx));

    set(array1, indx, -9);
    printf("%d\n", get(array1, indx));

    show_array(array1);
}