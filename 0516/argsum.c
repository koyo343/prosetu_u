#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i ;
    double d, sum ;
    
    for (sum = 0.0, i = 1; i < argc; ++i) {
	d = atof(argv[i]) ;
	printf("第%d引数: %g\n", i, d) ;
	sum += d ;
    }
    
    printf("合計: %g\n", sum) ;

    return 0 ;
}
