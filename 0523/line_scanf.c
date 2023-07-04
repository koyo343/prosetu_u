#include <stdio.h>

#define MAXDATA 100

int main(void){
    int point[MAXDATA][2] ;
    int n = 0, i ;
    
    while (scanf("%d %d", &point[n][0], &point[n][1]) != EOF)
	    n++ ;
    
    for (i = 0; i < n; ++i)
	    printf("x = %d y = %d\n", point[i][0], point[i][1]) ;

    return 0 ;
}