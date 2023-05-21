#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXLINE	2000

int main(int argc, char *argv[]){
  FILE *fp ;
  char buff[MAXLINE] ;
  int num = 1 ;

  if (argc != 3) { // 起動時にファイル名と文字列が指定されていることを確認
    fprintf(stderr, "Error: 検索文字列かファイル名が足りません\n") ;
    exit(1) ;
  }

  if ((fp = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "Error: ファイルのオープンエラー - %s\n", argv[2]) ;
    exit(2) ;
  }

  while (fgets(buff, MAXLINE, fp) != NULL) {
    if (strstr(buff, argv[1]) != NULL) {
      printf("%5d: %s", num, buff) ;
    }
    num++ ; /* 文字列の検出の有無にかかわらずインクリメント */
  }

  fclose(fp) ;

  return 0 ;
}