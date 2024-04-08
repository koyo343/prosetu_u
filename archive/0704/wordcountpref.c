#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "wordcount.h"

#define	MAXLINE	200

int main(int argc, char *argv[])
{
    FILE *fp ;
    char buff[MAXLINE] ;
    char prefname[MAXWORDSIZE] ;
    WORDCOUNT *wcp ;
    int i ;

    if (argc != 2) { /* 起動時のファイル名指定を確認 */
	fprintf(stderr, "エラー：ファイル名が指定されていません\n") ;
	exit(1) ;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
	fprintf(stderr, "エラー：ファイルをオープンできません - %s\n", argv[1]) ;
	exit(2) ;
    }

    wordcountInit() ;

    while (fgets(buff, MAXLINE, fp) != NULL) {
	/* 都道府県名を取得 */
	sscanf(buff, "%*d,%*[^,],%[^,]", prefname) ;

	/* 都道府県名を登録もしくは郵便番号数を更新 */
	wordcountRegister(prefname) ;
    }

    fclose(fp) ;

    /* 登録されている都道府県ごとの郵便番号数を表示 */
    for (wcp = wordcountGetFirst(); wcp != NULL; wcp = wordcountGetNext()) {
	printf("%5d: %s\n", wcGetCount(wcp), wcGetWord(wcp)) ;
    }

    return 0 ;
}
