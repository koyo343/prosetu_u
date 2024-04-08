#include <stdio.h>
#include "rational0.h"

RATIONAL newRational(int a, int b)
{
    RATIONAL v = {a, b} ;

    return v ;
}

RATIONAL raAdd(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunbo + b.bunshi * a.bunbo ;
    v.bunbo = a.bunbo * b.bunbo ;

    return v ;
}

RATIONAL raSub(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunbo - b.bunshi * a.bunbo ;
    v.bunbo = a.bunbo * b.bunbo ;

    return v ;
}

RATIONAL raMul(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunshi ;
    v.bunbo = a.bunbo * b.bunbo ;

    return v ;
}

RATIONAL raDiv(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunbo ;
    v.bunbo = a.bunbo * b.bunshi ;

    return v ;
}

int raEq(RATIONAL a, RATIONAL b)
{
    int v ;

    v = a.bunshi * b.bunbo - b.bunshi * a.bunbo ;

    return (v == 0) ;
}

int raGt(RATIONAL a, RATIONAL b)
{
    int v ;

    v = a.bunshi * b.bunbo - b.bunshi * a.bunbo ;

    return (v > 0) ;
}

int raLt(RATIONAL a, RATIONAL b)
{
    int v ;

    v = a.bunshi * b.bunbo - b.bunshi * a.bunbo ;

    return (v < 0) ;
}

void raPrint(RATIONAL v)
{
    printf("%d/%d", v.bunshi, v.bunbo) ;
}

void raPrintNl(RATIONAL v)
{
    raPrint(v) ;
    printf("\n") ;
}
