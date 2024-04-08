#include <stdio.h>

int main(void)
{
    int month, day ;

    /* 検索プログラムの月日の繰り返し入力部分だけ */
    while (1) { /* or for (;;) */
	fprintf(stderr, "月日：") ; /* プロンプト出力 */
	scanf("%d %d", &month, &day) ; /* 端末から月日を入力 */

	if (month == 0) { /* 月として0を入力すると終了 */
	    fprintf(stderr, "検索を終了します。\n") ;
	    break ; /* or exit(0) */
	}

	/* 検索プログラムではここに検索用のコードを書く */
	fprintf(stderr, "%d月%d日\n", month, day) ;
    }

    return 0 ;
}
