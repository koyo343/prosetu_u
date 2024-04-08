#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int main(void)
{
    char linebuff[MAXLINE] ;
    char *p ;
    int month, day, n ;

    while (1) { /* or for (;;) */
	/* エラー対策版・機能強化 */
	fprintf(stderr, "月日：") ; /* プロンプト出力 */
	p = fgets(linebuff, MAXLINE, stdin) ; /* 入力を文字列として取得 */
	if (p == NULL) { /* C-dが入力されると終了 */
	    fprintf(stderr, "処理を終了します。\n") ;
	    break ;
	}
	n = sscanf(linebuff, "%d%d", &month, &day) ; /* 文字列から数値を取得 */
	if (n == 0) { /* 数値として読み込めなかった */
	    if (strncmp(linebuff, "exit", 4) == 0) { /* 終了指示 */
		fprintf(stderr, "Error: 入処理を終了します。\n") ;
		break ;
	    }
	}
	if (n != 2) {
	    fprintf(stderr, "Error: 入力に誤りがあります。\n") ;
	    continue ; /* この後を省略して次のループに移る */
	}

/* もはや必要ない
	if (month == 0) {
	    fprintf(stderr, "検索を終了します。\n") ;
	    break ;or exit(0)
    }     */
	
	/* ここに検索用のコードを書く */
	fprintf(stderr, "%d月%d日\n", month, day) ;
    }

    return 0 ;
}
