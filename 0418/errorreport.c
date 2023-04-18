#include <stdio.h>

int main(void)
{
    fprintf(stderr, "これは、標準エラー出力を指定したエラーメッセージです。\n") ;
    
    printf("これは、プログラムの通常の出力です。\n") ;
    printf("これも、プログラムの通常の出力です。\n") ;
    fprintf(stdout, "これは、標準出力を明示的に指定した通常の出力です。\n") ;
    fprintf(stdout, "これも、標準出力を明示的に指定した通常の出力です。\n") ;

    return 0 ;
}
