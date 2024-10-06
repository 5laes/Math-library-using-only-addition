#include <stdio.h>
#include "mymath.h"

int unit_test1(long long (*f)(long long, long long), long long num1, long long num2, long long expected)
{
    long long result = f(num1, num2);
    if (result != expected)
    {
        return 0;
    }
    return 1;
}

int unit_test2(long long (*f)(long long), long long num1, long long expected)
{
    long long result = f(num1);
    if (result != expected)
    {
        return 0;
    }
    return 1;
}

void tests()
{
    if(!unit_test1(add, 5, 5, 10))   printf("add test 1 failed\n");
    if(!unit_test1(add, -5, -4, -9)) printf("add test 2 failed\n");
    if(!unit_test1(add, -5, 6, 1))   printf("add test 3 failed\n");
    if(!unit_test1(add, 5, -6, -1))  printf("add test 4 failed\n");

    if(!unit_test1(subtract, 10, 5, 5))    printf("subtract test 1 failed\n");
    if(!unit_test1(subtract, -10, -5, -5)) printf("subtract test 2 failed\n");
    if(!unit_test1(subtract, -5, 10, -15)) printf("subtract test 3 failed\n");
    if(!unit_test1(subtract, 5, -10, 15))  printf("subtract test 4 failed\n");

    if(!unit_test1(multiply, 9, 9, 81))   printf("multiply test 1 failed\n");
    if(!unit_test1(multiply, 9, -9, -81)) printf("multiply test 2 failed\n");
    if(!unit_test1(multiply, -9, 9, -81)) printf("multiply test 3 failed\n");
    if(!unit_test1(multiply, -9, -9, 81)) printf("multiply test 4 failed\n");

    if(!unit_test1(exponent, 5, 3, 125))   printf("exponent test 1 failed\n");
    if(!unit_test1(exponent, -5, 3, -125)) printf("exponent test 2 failed\n");
    if(!unit_test1(exponent, -5, 2, 25))   printf("exponent test 3 failed\n");
    if(!unit_test1(exponent, -5, 2, 25))   printf("exponent test 4 failed\n");
    if(!unit_test1(exponent, 5, -5, 0))    printf("exponent test 5 failed\n");
    if(!unit_test1(exponent, -5, -5, 0))   printf("exponent test 6 failed\n");

    if(!unit_test1(tetration, 3, 3, 7625597484987))   printf("tetration test 1 failed\n");
    if(!unit_test1(tetration, 3, -3, 0))              printf("tetration test 2 failed\n");
    if(!unit_test1(tetration, -3, 3, 0))              printf("tetration test 3 failed\n");
    if(!unit_test1(tetration, -3, -3, 0))             printf("tetration test 4 failed\n");

    if(!unit_test1(divide, 25, 5, 5))   printf("divide test 1 failed\n");
    if(!unit_test1(divide, 26, 5, 5))   printf("divide test 2 failed\n");
    if(!unit_test1(divide, 25, 0, 0))   printf("divide test 3 failed\n");
    if(!unit_test1(divide, -25, 5, -5)) printf("divide test 4 failed\n");
    if(!unit_test1(divide, -26, 5, -5)) printf("divide test 5 failed\n");
    if(!unit_test1(divide, 25, -5, -5)) printf("divide test 6 failed\n");
    if(!unit_test1(divide, 26, -5, -5)) printf("divide test 7 failed\n");
    if(!unit_test1(divide, -25, -5, 5)) printf("divide test 8 failed\n");
    if(!unit_test1(divide, -26, -5, 5)) printf("divide test 9 failed\n");

    if(!unit_test2(factorial, 10, 3628800)) printf("factorial test 1 failed\n");
    if(!unit_test2(factorial, -10, 0))      printf("factorial test 2 failed\n");
}