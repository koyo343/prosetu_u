#include <stdio.h>
#include <stdlib.h>

struct kisyou { /* 気温データを管理するレコード */
    int month ;
    int day ;
    int hour ;
    double kion ;
} ;

/* 実験のため配列のサイズを少し小さく */
#define ARRAYSIZE 1000

int main(void)
{
    FILE *fp ;
    int month, day, hour ;
    double data ;
    struct kisyou kisyoudata[ARRAYSIZE] ; /* 構造体の配列を追加 */
    int size, i ;

    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ;
    }

    size = 0 ;
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	/* すべてのデータを構造体のメンバに保存 */
	kisyoudata[size].month = month ;
	kisyoudata[size].day = day ;
	kisyoudata[size].hour = hour ;
	kisyoudata[size].kion = data ;
	size++ ;
    }

    fclose(fp) ;

    for (i = 0; i < size; i++) {
	printf("%d月%d日%d時 %.1f\n", /* 構造体のメンバを出力 */
		kisyoudata[i].month, kisyoudata[i].day,
		kisyoudata[i].hour, kisyoudata[i].kion) ;
    }

    return 0 ;
}
