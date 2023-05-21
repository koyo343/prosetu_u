#include <stdio.h>

#include "kion-stat-heikin.h"

/* 配列で渡された１時間毎の気温をすべて出力 */
void kion_print(double array[], int size)
{
    int i ;

    for (i = 0; i < size; i++) {
	printf("%d時: %.1f\n", i, array[i]) ;
    }
}

/* 配列で渡された気温の平均値を求めて返す */
double kion_heikin(double array[], int size)
{
    int i ;
    double sum = 0.0 ; /* 合計値の初期化 */

    for (i = 0; i < size; i++) {
	sum += array[i] ; /* 気温の合計値を求める */
    }

    return sum/size ; /* 気温の平均値を求め返す */
}
