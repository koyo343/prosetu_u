#include <stdio.h>
#include <stdlib.h>

/* 配列に一年間のデータ(9千弱)を保存できる大きさとして定義 */
#define ARRAYSIZE 10000

int main(void)
{
    FILE *fp ;
    int month, day, hour ;
    double data ;
    double kion[ARRAYSIZE] ;
    int size ; /* 配列の添字、配列に読み込まれたデータ数として利用 */
    int i ;

    /* ここからはファイルの入力処理 
    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ;
    } */

    if ((fp = fopen("data/kion_data/kion-20180401.csv", "r")) == NULL)
    {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }

    size = 0 ; /* 読み込んだデータの格納位置を初期化 */
    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	/* month, day, hourは読み取ったが今回は使用しない */
	kion[size] = data ; /* 読み込んだデータは配列のはじめから順に格納 */
	size++;
    }

    fclose(fp) ;

    /* ここからは配列に読み込まれたデータの処理 */
    for (i = 0; i < size; i++) {
	printf("kion[%d]: %.1f\n", i, kion[i]) ;
    }

    return 0 ;
}
