#include <stdio.h>
#include <stdlib.h> /* exit関数が定義されている */

#define	MAXFILENAME 100 /* ファイル名の最大長 */

int main(void)
{
    char filename[MAXFILENAME] ;
    FILE *fp ; /* ファイルポインタ（ファイルの識別子） */
    int month, day, hour ;
    double data ;

    /* プロンプトの出力とファイル名の入力 */
    fprintf(stderr, "データファイル名：") ;
    scanf("%s", filename) ; /* 端末からファイル名を入力 */

    /* ファイルのオープン：ファイル名 filename と入力用の利用 "r" を指定 */
    if ((fp = fopen(filename, "r")) == NULL) {
	/* 以下の２行はファイルがオープンできなかった時の処理 */
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ; /* プログラムをここで終了させる */
    }

    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	printf("%d月%d日%d時 %.1f\n", month, day, hour, data) ;
    }

    /* ファイルのクローズ */
    fclose(fp) ;

    return 0 ;
}
