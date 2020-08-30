#include <stdio.h>

int add(int x)
{
    return x;
}

int add(float x)
{
    return x;
}

int main()
{
    printf("%d", add(-11));
    printf("%f", add(99.99));

    return 1;
}