#include <stdio.h>

#define MAXLINE 100

int main(void)
{
    char linebuff[MAXLINE] ;
    int month, day, n ;

    while (1) { /* or for (;;) */
	/* エラー対策版 */
	fprintf(stderr, "月日：") ; /* プロンプト出力 */
	fgets(linebuff, MAXLINE, stdin) ; /* 入力を文字列として取得 */
	n = sscanf(linebuff, "%d %d", &month, &day) ; /* 文字列から数値を取得 */
	if (n != 2) { /* sscanfは正しく読み込めたデータ数を返す */
	    fprintf(stderr, "Error: 入力に誤りがあります。\n") ;
	    continue ; /* この後を省略して次のループに移る */
	}

	if (month == 0) { /* 月に0を指定すると終了させる */
	    fprintf(stderr, "検索を終了します。\n") ;
	    break ; /* or exit(0) */
	}

	/* ここに検索用のコードを書く */
	fprintf(stderr, "%d月%d日\n", month, day) ;
    }

    return 0 ;
}
