#include "kionstat.h"

/* 配列で渡された気温の平均値を求めて返す */
double kion_heikin(double array[], int size){
    int i ;
    double sum = 0.0 ;

    for (i = 0; i < size; i++) {
	sum += array[i] ;
    }

    return sum/size ;
}

/* 配列で渡された気温の最大値を求めて返す */
double kion_max(double array[], int size){
    int i ;
    double vmax = array[0] ; /* 最大値の候補 */

    for (i = 1; i < size; i++) {
	if (array[i] > vmax) /* 最大値の候補よりも大きい値 */
	    vmax = array[i] ; /* その値で最大値の候補を更新する */
    }

    return vmax ;
}

/* 配列で渡された気温の最小値を求めて返す */
double kion_min(double array[], int size){
    int i ;
    double vmin = array[0] ;

    for (i = 1; i < size; i++) {
	if (array[i] < vmin)
	    vmin = array[i] ;
    }

    return vmin ;
}
