#include <stdio.h>

#include "kion-htmlreport.h"

#define	MAXFILENAME 100 /* ファイル名の最大長 */

/* １年間のデータを読み込めるように */
#define ARRAYSIZE 10000

int main(void){
    char filename[MAXFILENAME] ;
    struct kisyou kisyoudata[ARRAYSIZE] ; /* 構造体の配列を追加 */
    int size ; /* 配列に読み込まれたデータ数 */

    fprintf(stderr, "データファイル名：") ;
    scanf("%s", filename) ; /* 端末からファイル名を入力 */

    /* データファイルの読み込み */
    size = readfile(filename, kisyoudata, ARRAYSIZE) ;

    /* 統計データのHTML整形出力 */
    html_report(kisyoudata, size) ;

    return 0 ;
}
