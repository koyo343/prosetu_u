#include <stdio.h>
#include "rational.h"

int main(void)
{
    RATIONAL x1, x2, x, v, eps, c1, c2;

    eps = newRational(2, 1000);
    c1 = newRational(1, 1);
    c2 = newRational(2, 1);
    x1 = newRational(0, 1);
    x2 = newRational(1, 1);

    while (raGt(raSub(x2, x1), eps))
    {
        x = raDiv(raAdd(x1, x2), c2);
        v = raSub(raMul(x, raAdd(raMul(x, x), c1)), c1);

        printf("x1="), raPrint(x1);
        printf("x2="), raPrint(x2);
        printf("x="), raPrint(x);
        printf("v="), raPrintNl(v);

        if (raGt(v, newRational(0, 1)))
            x2 = x;
        else
            x1 = x;
    }

    x = raDiv(raAdd(x1, x2), c2);
    printf("answer = "), raPrintNl(x);

    return 0;
}