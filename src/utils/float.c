#include "../headers/float.h"


double round_ndecimal(double num, int n)
{
    int factor = pow(10, n);

    num *= factor;
    num  = round(num);
    num /= factor;

    return num;
}

