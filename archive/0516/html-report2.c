#include <stdio.h>

#include "kion-htmlreport.h"
#include "kionstat.h"

#define DAYARRAY 24

/* HTMLによる気温表の出力 */
void html_report(struct kisyou array[], int size)
{
    double kion[DAYARRAY] ;
    int i, di ;
    double vmax, vmin ;

    /* HTMLのヘッダー部分 */
    printf("<HTML>\n<HEAD>\n") ;
    printf("<TITLE>気温データ</TITLE>\n") ;
    printf("</HEAD>\n") ;
    /* 文書の本体の開始 */
    printf("<BODY>\n") ;
    /* 見出しの表示 */
    printf("<H1>日別気温統計データ</H1>\n") ;
    /* 表のヘッダー部分の開始 */
    printf("<TABLE border=1>\n") ;
    printf("<TR><TH>月日</TH><TH>平均</TH><TH>最高</TH><TH>最低</TH><TH>日較差</TH></TR>\n") ;

    /* 表の本体部分の出力 */
    for (i = 0; i < size; i += DAYARRAY) { /* 一日単位で処理 */
	for (di = 0; di < DAYARRAY; di++) {
	    /* １日分の気温を統計計算用の配列に転記 */
	    kion[di] = array[i + di].kion ;
	}

	vmax = kion_max(kion, DAYARRAY) ;
	vmin = kion_min(kion, DAYARRAY) ;
	/* 表の本体の１行出力 */
	printf("<TR><TD>%d月%d日</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD><TD>%.1f</TD></TR>\n",
			array[i].month, array[i].day, 
			kion_heikin(kion, DAYARRAY),
			vmax,
			vmin,
			vmax - vmin ) ;
    }

    printf("</TABLE>\n") ; /* 表の終端 */
    printf("</BODY>\n") ; /* 文書本体の終端 */
    printf("</HTML>\n") ; /* HTMLの終端 */
}
