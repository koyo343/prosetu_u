#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 100
#define MAXLINE 100

int main(void){
    int point[MAXDATA][2] ;
    char buff[MAXLINE] ;
    int n = 0, line = 0, i ;
    
    while (fgets(buff, MAXLINE, stdin) != NULL){
	    line++ ; /* 行を読み込んだら行番号の更新 */
	/* コメント行と空行の検出 */
        if (buff[0] == '#' ||  buff[0] == '¥n')
            continue ; /* 以下の処理は中断して次のループへ */
        
        if (sscanf(buff, "%d %d", &point[n][0], &point[n][1]) != 2){
            fprintf(stderr, "エラー (%d):  %s", line, buff) ;
            exit(2) ;
        }
	    n++ ; /* データを取得したら添え字を更新 */
    }
    
    for (i = 0; i < n; ++i)
	    printf("x = %d, y = %d¥n", point[i][0], point[i][1]) ;

    return 0 ;
}