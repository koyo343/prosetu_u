#include <stdio.h>

/* プロトタイプ宣言：インターフェース */
double add(double x, double y) ;

int main(void){
    printf("%f\n", add(1.0, 2.0)) ;

    return 0 ;
}

/* 関数定義：実装 */
double add(double x, double y){
    return x + y ;
}
