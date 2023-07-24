#include <stdio.h>

typedef struct rational {
    int bunshi ;
    int bunbo ;
} RATIONAL ;

int main(void)
{
    RATIONAL a = {2, 3} ; /* 初期化された有理数（次も） */
    RATIONAL b = {-3, 5} ;
    RATIONAL x ;

    /* 有理数の表示 */
    printf("a = %d/%d\n", a.bunshi, a.bunbo) ;
    printf("b = %d/%d\n", b.bunshi, b.bunbo) ;

    /* 加算 */
    x.bunshi = a.bunshi * b.bunbo + b.bunshi * a.bunbo ;
    x.bunbo = a.bunbo * b.bunbo ;
    printf("a + b = %d/%d\n", x.bunshi, x.bunbo) ;

    /* 減算 */
    x.bunshi = a.bunshi * b.bunbo - b.bunshi * a.bunbo ;
    x.bunbo = a.bunbo * b.bunbo ;
    printf("a - b = %d/%d\n", x.bunshi, x.bunbo) ;

    /* 乗算 */
    x.bunshi = a.bunshi * b.bunshi ;
    x.bunbo = a.bunbo * b.bunbo ;
    printf("a * b = %d/%d\n", x.bunshi, x.bunbo) ;

    /* 除算 */
    x.bunshi = a.bunshi * b.bunbo ;
    x.bunbo = a.bunbo * b.bunshi ;
    printf("a / b = %d/%d\n", x.bunshi, x.bunbo) ;

    /* 等値比較 */
    if (a.bunshi * b.bunbo - b.bunshi * a.bunbo == 0)
	printf("aとbは等しい。\n") ;
    else
	printf("aとbは異なる。\n") ;

    /* 大小比較 */
    if (a.bunshi * b.bunbo - b.bunshi * a.bunbo > 0)
	printf("aがbより大きい。\n") ;
    else
	printf("aよりbが大きい。\n") ;

    return 0 ;
}
