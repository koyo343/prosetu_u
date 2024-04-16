#include <stdio.h>
#include <stdlib.h> /* exit関数が定義されている */

int main(void)
{
    FILE *fp ; /* ファイルポインタ（ファイルの識別子） */
    int month, day, hour ;
    double data ;

    /* ファイルのオープン：ファイル名と入力用の利用を指定
    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
	以下の２行はファイルがオープンできなかった時の処理 
	fprintf(stderr, "Error: File Open\n") ;
	exit(1) ;
    }*/

    if ((fp = fopen("data/kion_data/kion-20180401.csv", "r")) == NULL)
    {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }

    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	    printf("%d月%d日%d時 %.1f\n", month, day, hour, data) ;
    }

    /* ファイルのクローズ */
    fclose(fp) ;

    return 0 ;
}
