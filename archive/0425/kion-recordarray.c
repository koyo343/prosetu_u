#include <stdio.h>
#include <stdlib.h>

/* ファイルの内容を構造体の配列に記録しデータ数を返す */
int readfile(char filename[], int amonth[], int aday[], int ahour[], double kion[], int amax)
{
    FILE *fp ;
    int month, day, hour ;
    double data ;
    int size ;

    /* ここからはファイルの入力処理 */
    if ((fp = fopen(filename, "r")) == NULL) {
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ;
    }

    size = 0 ; /* 読み込んだデータの格納位置を初期化 */
    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	if (size >= amax) {
	    fprintf(stderr, "Error: 配列の容量が不足しています。\n") ;
	    exit(2) ;
	}
	/* すべてのデータを配列に保存 */
	amonth[size] = month ;
	aday[size] = day ;
	ahour[size] = hour ;
	kion[size] = data ;
	size++ ; /* 次に値を格納する位置の添字に更新 */
    }

    fclose(fp) ;

    return size ; /* 読み込んだデータ数を返す */
}

/* ひとかたまりのデータだがデータを個別に関数に渡す */
void printrecord(int d1, int d2, int d3, double v)
{
    printf("%d月%d日%d時 %.1f\n", d1, d2, d3, v) ;
}

#define	MAXFILENAME 100 /* ファイル名の最大長 */

/* 実験のため配列のサイズを少し小さく */
#define ARRAYSIZE 1000

int main(void)
{
    char filename[MAXFILENAME] ;
    /* 月、日、時刻を記録する配列を追加 */
    int montharray[ARRAYSIZE], dayarray[ARRAYSIZE], hourarray[ARRAYSIZE] ;
    double kion[ARRAYSIZE] ;
    int size, i ;

    fprintf(stderr, "データファイル名：") ;
    scanf("%s", filename) ; /* 端末からファイル名を入力 */

    size = readfile(filename, montharray, dayarray, hourarray,
		kion, ARRAYSIZE) ;

    for (i = 0; i < size; i++) {
	/* 複数配列：配列の数や順番に注意．．．要素が増えると？ */
	printrecord(montharray[i], dayarray[i], hourarray[i],
		kion[i]) ;
    }

    return 0 ;
}
