#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "wordcount.h"

int main(int argc, char *argv[])
{
    FILE *fp ;
    char buff[MAXWORDSIZE] ;
    WORDCOUNT *wcp ;
    int i, cmax ;

    if (argc != 2) { /* 起動時のファイル名指定を確認 */
	fprintf(stderr, "エラー：ファイル名が指定されていません\n") ;
	exit(1) ;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
	fprintf(stderr, "エラー：ファイルをオープンできません - %s\n", argv[1]) ;
	exit(2) ;
    }

    wordcountInit() ;

    fscanf(fp, "%*[^A-Za-z]") ; /* 最初に単語以外の文字があれば読み捨て */
    while (fscanf(fp, "%[A-Za-z]%*[^A-Za-z]", buff) != EOF) {
	/* すべての英大文字を英子文字に変換 */
	for (i = 0; buff[i] != '\0'; i++)
	    buff[i] = tolower((unsigned char)buff[i]) ;

	/* 単語を登録もしくは出現回数を更新 */
	wordcountRegister(buff) ;
    }

    fclose(fp) ;

    /* 単語の出現回数の最大値を取得 */
    for (cmax = 0, wcp = wordcountGetFirst(); wcp != NULL; wcp = wordcountGetNext()) {
	if (wcGetCount(wcp) > cmax)
	    cmax = wcGetCount(wcp) ;
    }

    /* 最大の出現回数の1/10以上の出現回数の単語を表示 */
    for (wcp = wordcountGetFirst(); wcp != NULL; wcp = wordcountGetNext()) {
	if (wcGetCount(wcp) * 10 >= cmax)
	    printf("%5d: %s\n", wcGetCount(wcp), wcGetWord(wcp)) ;
    }

    return 0 ;
}
