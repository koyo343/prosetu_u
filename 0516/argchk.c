#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
	fprintf(stderr, "引数を１個だけ指定してください．\n") ;
	exit(1) ;
    }
    
    printf("引数: %s\n", argv[1]) ;

    return 0 ;
}
