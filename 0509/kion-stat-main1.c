#include <stdio.h>

/* 配列で渡された１時間毎の気温をすべて出力 */
void kion_print(double array[], int size) ;
/* 配列で渡された気温の平均値を求めて返す */
double kion_heikin(double array[], int size) ;

#define ARRAYSIZE 24

int main(void)
{
    /* １時間毎の２４個の気温データ */
    double kion[ARRAYSIZE] =
		{12.8,12.0,11.4,11.2,10.6,10.6,10.3,10.6,
		13.1,16.9,20.1,22.2,21.9,22.5,23.9,24.1,
		22.9,21.9,20.1,18.9,17.6,17.0,16.4,15.7} ;

    kion_print(kion, ARRAYSIZE) ;

    printf("-----\n") ;

    printf("平均気温: %.1f\n", kion_heikin(kion, ARRAYSIZE)) ;

    return 0 ;
}
