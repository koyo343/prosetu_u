#include <stdio.h>
#include <stdlib.h>

#define	MAXFILENAME 100 /* ファイル名の最大長 */

/* 実験のため配列のサイズを少し小さく */
#define ARRAYSIZE 1000

int main(void)
{
    char filename[MAXFILENAME] ;
    FILE *fp ;
    int month, day, hour ;
    double data ;
    double kion[ARRAYSIZE] ;
    int size ; /* 配列の添字、配列に読み込まれたデータ数として利用 */
    int i ;

    fprintf(stderr, "データファイル名：") ;
    scanf("%s", filename) ; /* 端末からファイル名を入力 */

    /* ファイルのオープン：ファイル名 filename と入力用の利用 "r" を指定 */
    if ((fp = fopen(filename, "r")) == NULL) {
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ;
    }

    size = 0 ; /* 読み込んだデータの格納位置を初期化 */
    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	/* month, day, hourは読み取ったが今回は使用しない */
	if (size >= ARRAYSIZE) {
	    fprintf(stderr, "Error: 配列の容量が不足しています。\n") ;
	    exit(2) ;
	}
	kion[size] = data ; /* 読み込んだデータは配列のはじめから順に格納 */
	size++ ; /* 次に値を格納する位置の添字に更新 */
    }

    fclose(fp) ;

    /* ここからは配列に読み込まれたデータの処理 */
    for (i = 0; i < size; i++) {
	printf("kion[%d]: %.1f\n", i, kion[i]) ;
    }

    return 0 ;
}
