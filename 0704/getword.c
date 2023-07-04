#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORDSIZE 100

int main(int argc, char *argv[])
{
    FILE *fp ;
    char buff[MAXWORDSIZE] ;
    int i ;

    if (argc != 2) { /* 起動時のファイル名指定を確認 */
	fprintf(stderr, "Error: No File Name\n") ;
	exit(1) ;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
	fprintf(stderr, "Error: File Open - %s\n", argv[1]) ;
	exit(2) ;
    }

    /* 1単語ごとに取得して表示 */
    fscanf(fp, "%*[^A-Za-z]") ; /* 最初の単語以外の文字があれば読み捨て */
    while (fscanf(fp, "%99[A-Za-z]%*[^A-Za-z]", buff) != EOF) {
	/* すべての英大文字を英小文字に変換 */
	for (i = 0; buff[i] != '\0'; i++)
	    buff[i] = tolower((unsigned char)buff[i]) ;

	printf("%s\n", buff) ;
    }

    fclose(fp) ;

    return 0 ;
}