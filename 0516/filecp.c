#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	2000

int main(int argc, char *argv[]){
  FILE *fpr, *fpw ;
  char buff[MAXLINE] ;

  if (argc != 3) { // 起動時にファイル名が指定されていることを確認
    fprintf(stderr, "Error: ファイル名が足りません\n") ;
    exit(1) ;
  }

  if ((fpr = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error: ファイルの入力オープンエラー - %s\n", argv[1]) ;
    exit(2) ;
  }

  if ((fpw = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Error: ファイルの出力オープンエラー - %s\n", argv[2]) ;
    exit(2) ;
  }

  while (fgets(buff, MAXLINE, fpr) != NULL) { /* ファイルの読み込み */
    fputs(buff, fpw) ; /* ファイルの書き出し */
  }

  fclose(fpr) ;
  fclose(fpw) ;

  return 0 ;
}