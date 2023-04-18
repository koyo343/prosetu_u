#include <stdio.h>
#include <stdlib.h>

/* 実験のため配列のサイズを少し小さく */
#define ARRAYSIZE 1000

int main(void)
{
    FILE *fp ;
    int month, day, hour ;
    double data ;
    /* 月、日、時刻を記録する配列を追加 */
    int montharray[ARRAYSIZE], dayarray[ARRAYSIZE], hourarray[ARRAYSIZE] ;
    double kion[ARRAYSIZE] ;
    int size, i ;

    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ;
    }

    size = 0 ;
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	/* すべてのデータを配列に保存 */
	montharray[size] = month ;
	dayarray[size] = day ;
	hourarray[size] = hour ;
	kion[size] = data ;
	size++ ;
    }

    fclose(fp) ;

    for (i = 0; i < size; i++) {
	printf("%d月%d日%d時 %.1f\n",
	    montharray[i], dayarray[i], hourarray[i], kion[i]) ;
    }

    return 0 ;
}