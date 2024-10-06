long long add(const long long augend, const long long addend)
{
    long long sum = augend + addend;
    return sum;
}

long long subtract(const long long minuend, const long long subtrahend)
{
    long long sum = add(minuend, -subtrahend); // might be cheating idk
    return sum;
}

long long multiply(const long long multiplier, const long long multiplicand)
{
    if (multiplicand < 0 && multiplier < 0)
    {
        long long difference = 0;
        for (long long i = 0; i > multiplicand; i = subtract(i, 1))
        {
            difference = subtract(difference, multiplier);
        }
        return difference;
    }

    if (multiplicand < 0) return multiply(multiplicand, multiplier);

    long long sum = 0;
    for (long long i = 0; i < multiplicand; i++)
    {
        sum = add(sum, multiplier);
    }
    return sum;
}

long long exponent(const long long base_power, const long long base_exponent)
{
    if (base_exponent < 0) return 0;
    if (base_exponent == 0) return 1;

    long long product = base_power;
    for (long long i = 1; i < base_exponent; i++)
    {
        product = multiply(product, base_power);
    }
    return product;
}

long long tetration(const long long base_power, const long long base_tetrant)
{
    if (base_power < 0 || base_tetrant < 0) return 0;

    long long power = base_power;
    for (long long i = 1; i < base_tetrant; i++)
    {
        power = exponent(base_power, power);
    }
    return power;
}

/*
    I could continue with pentation, hexation and everything after that but
    they are gonna look the same as tetration and exponent just that they 
    are gonna cal the function before them. tetration would be called in 
    pentation and pentation would be called in hexation and continuing like 
    that. The numbers are gonna get to big as well so no point.
*/

long long divide(const long long numerator, const long long denominator)
{
    if (denominator == 0) return 0;

    long long quotient = 0;

    if (numerator < 0 && denominator < 0)
    {
        long long difference = numerator;
        for (; difference <= denominator; quotient++)
        {
            difference = subtract(difference, denominator);
        }
        return quotient;
    }

    if (numerator < 0)
    {
        long long difference = 0;
        long long check = add(numerator, denominator);
        /*
            reason why we do numerator + denominator is to not run the loop 
            more than we need to. lets say numerator = -25 and denominator = 5
            we need to check how many times 5 fits in to -25 which is -5 five times.
            so we start difference at 0 and subtract the denominator from difference 
            each loop until we reach -25. each run checks if difference is bigger than
            or equal to -25. so difference will be -5 -10 -15 -20 -25. and since we do
            >= it will run an extra time when we reach -25. we can fix this by just
            checking > but if numerator would be between 26-29 it would make the loop
            run 6 times instead of 5 and the quotient would be -6 which is incorrect.
            to fix both these cases we change what the difference compares to to
            numerator + denominator (-25 + 5) which equals -20. and thats why we check
            >= so we dont return early when difference is -20 and do one more run.

            we could also change quotient to start at 1 to work around this
            but that does not feel right. dont know which is more mathematically correct
        */
        for (; difference >= check; quotient = subtract(quotient, 1))
        {
            difference = subtract(difference, denominator);
        }
        return quotient;
    }

    if (denominator < 0)
    {
        long long difference = 0;
        long long check = add(numerator, denominator);
        // same reason as above
        for (; difference <= check; quotient = subtract(quotient, 1))
        {
            difference = subtract(difference, denominator);
        }
        return quotient;
    }

    long long difference = numerator;
    for (; difference >= denominator; quotient++)
    {
        difference = subtract(difference, denominator);
    }
    return quotient;
}

long long factorial(const long long factor)
{
    if (factor < 0) return 0;

    long long product = factor;
    for (long long difference = factor; difference > 1;)
    {
        difference = subtract(difference, 1);
        product = multiply(product, difference);
    }
    return product;
}