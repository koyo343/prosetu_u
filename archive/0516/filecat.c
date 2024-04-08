#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	2000

int main(int argc, char *argv[])
{
  FILE *fp ;
  char buff[MAXLINE] ;

  if (argc != 2) { // 起動時にファイル名が指定されていることを確認
    fprintf(stderr, "Error: ファイル名がありません\n") ;
    exit(1) ;
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error: ファイルのオープンエラー - %s\n", argv[1]) ;
    exit(2) ;
  }

  while (fgets(buff, MAXLINE, fp) != NULL) {
    fputs(buff, stdout) ;
  }

  fclose(fp) ;

  return 0 ;
}