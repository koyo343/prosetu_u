#include <stdio.h>
#include <stdlib.h>

/* 配列で渡された気温の平均値を求めて返す */
double kion_heikin(double array[], int size)
{
    int i ;
    double sum = 0.0 ;

    for (i = 0; i < size; i++) {
	sum += array[i] ;
    }

    return sum/size ;
}

/* 配列で渡された気温の最大値を求めて返す */
double kion_max(double array[], int size)
{
    int i ;
    double vmax = array[0] ; /* 最大値の候補 */

    for (i = 1; i < size; i++) {
	if (array[i] > vmax) /* 最大値の候補よりも大きい値 */
	    vmax = array[i] ; /* その値で最大値の候補を更新する */
    }

    return vmax ;
}

/* 配列で渡された気温の最小値を求めて返す */
double kion_min(double array[], int size)
{
    int i ;
    double vmin = array[0] ;

    for (i = 1; i < size; i++) {
	if (array[i] < vmin)
	    vmin = array[i] ;
    }

    return vmin ;
}

struct kisyou { /* 気温データを管理するレコード */
    int month ;
    int day ;
    int hour ;
    double kion ;
} ;

/* ファイルの内容を構造体の配列に記録しデータ数を返す */
int readfile(char filename[], struct kisyou array[], int amax)
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
	/* すべてのデータを構造体のメンバに保存 */
	array[size].month = month ;
	array[size].day = day ;
	array[size].hour = hour ;
	array[size].kion = data ;
	size++ ; /* 次に値を格納する位置の添字に更新 */
    }

    fclose(fp) ;

    return size ; /* 読み込んだデータ数を返す */
}

#define	MAXFILENAME 100 /* ファイル名の最大長 */

/* １年間のデータを読み込めるように */
#define ARRAYSIZE 10000
#define DAYARRAY 24

int main(void)
{
    char filename[MAXFILENAME] ;
    struct kisyou kisyoudata[ARRAYSIZE] ; /* 構造体の配列を追加 */
    double kion[DAYARRAY] ;
    int size ; /* 配列に読み込まれたデータ数 */
    int i, di ;

    fprintf(stderr, "データファイル名：") ;
    scanf("%s", filename) ; /* 端末からファイル名を入力 */

    size = readfile(filename, kisyoudata, ARRAYSIZE) ;

    /* 一日ごとの気温の統計値の出力 */
    for (i = 0; i < size; i += DAYARRAY) { /* 一日単位で処理 */
	for (di = 0; di < DAYARRAY; di++) {
	    /* １日分の気温を統計計算用の配列に転記 */
	    kion[di] = kisyoudata[i + di].kion ;
	}

	printf("%d月%d日: %.1f, %.1f, %.1f\n",
			kisyoudata[i].month, kisyoudata[i].day, 
			kion_heikin(kion, DAYARRAY),
			kion_max(kion, DAYARRAY),
			kion_min(kion, DAYARRAY) ) ;
    }

    return 0 ;
}
