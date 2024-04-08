#include <stdio.h>
#include "rational.h"

/* 最大公約数を求める(ユークリッドの互除法) */
int gcd(int a, int b)
{
    if (b == 0)
        return a ;

    return gcd(b , a % b) ;
}

RATIONAL raReduce(RATIONAL x)
{
    int n ;

    /* 最大公約数を使用した簡約処理 */
    n = gcd(x.bunshi ,x.bunbo) ;
    x.bunshi /= n ;
    x.bunbo /= n ;

    /* 分母が負なら正の数に変換 */
    if (x.bunbo < 0) {
        x.bunshi = -x.bunshi ;
        x.bunbo = -x.bunbo ;
    }

    return x ;
}

RATIONAL newRational(int a, int b)
{
    RATIONAL v = {a, b} ;

    return raReduce(v) ;
}

RATIONAL raAdd(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunbo + b.bunshi * a.bunbo ;
    v.bunbo = a.bunbo * b.bunbo ;

    return raReduce(v) ;
}

RATIONAL raSub(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunbo - b.bunshi * a.bunbo ;
    v.bunbo = a.bunbo * b.bunbo ;

    return raReduce(v) ;
}

RATIONAL raMul(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunshi ;
    v.bunbo = a.bunbo * b.bunbo ;

    return raReduce(v) ;
}

RATIONAL raDiv(RATIONAL a, RATIONAL b)
{
    RATIONAL v ;

    v.bunshi = a.bunshi * b.bunbo ;
    v.bunbo = a.bunbo * b.bunshi ;

    return raReduce(v) ;
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
    if (v.bunbo == 1)
        printf("%d", v.bunshi) ;
    else
        printf("%d/%d", v.bunshi, v.bunbo) ;
}

void raPrintNl(RATIONAL v)
{
    raPrint(v) ;
    printf("\n") ;
}
