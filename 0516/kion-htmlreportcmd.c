#include <stdio.h>

#include "kion-htmlreport.h"

/* １年間のデータを読み込めるように */
#define ARRAYSIZE 10000

int main(int argc, char *argv[])
{
    struct kisyou kisyoudata[ARRAYSIZE] ; /* 構造体の配列を追加 */
    int size ; /* 配列に読み込まれたデータ数 */

    if (argc != 2) {
	fprintf(stderr, "データファイル名を指定してください．\n") ;
	exit(1) ;
    }
    
    /* データファイルの読み込み */
    size = readfile(argv[1], kisyoudata, ARRAYSIZE) ;

    /* 統計データのHTML整形出力 */
    html_report(kisyoudata, size) ;

    return 0 ;
}
