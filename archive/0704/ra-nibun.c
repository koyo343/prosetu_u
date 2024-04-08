#include <stdio.h>
#include "rational.h"

int main(void)
{
    RATIONAL x1, x2, x, v ;
    RATIONAL eps, c1, c2 ;

    eps = newRational(2, 1000);
    c1 = newRational(1,1) ;
    c2 = newRational(2,1) ;

    x1 = newRational(0, 1);
    x2 = newRational(1, 1);

    while (raGt(raSub(x2, x1), eps)) {
	/* (b) x = (x1 + x2) / 2.0; に相当する計算式 */
	x = raDiv(raAdd(x1, x2), c2) ;

	/* 以下は v = x * (x * x + 1) - 1 に相当する式．そのまま使用 */
	v = raSub(raMul(x, raAdd(raMul(x, x), c1)), c1);

	/* x1, x2, x, v の表示 */
	printf("x1 = "); raPrint(x1);
	printf(", x2 = "); raPrint(x2);
	printf(", x = "); raPrint(x);
	printf(", v = "); raPrintNl(v);

	if (raGt(v, newRational(0,1)))
	    x2 = x;
	else
	    x1 = x;
    }

    /* (d) x = (x1 + x2) / 2.0; に相当する計算式 */
    x = raDiv(raAdd(x1, x2), c2) ;
    /* (e) 求まった解 x の表示 */
    printf("answer = ") ; raPrint(x) ;

    return 0;
}
