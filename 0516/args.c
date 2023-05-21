#include <stdio.h>

int main(int argc, char *argv[]){
    int i ;
    
    printf("コマンド名: %s\n", argv[0]) ;
    printf("引数の個数: %d\n", argc - 1) ;
    
    for (i = 1; i < argc; ++i)
	printf("第%d引数: %s\n", i, argv[i]) ;

    return 0 ;
}
