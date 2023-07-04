#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	200

int main(void){
    FILE *fp;
    char buff[MAXLINE] ;
    int lgcode ;
    char str[200] ;

    if ((fp = fopen("YUBIN.csv", "r")) == NULL){
	    fprintf(stderr, "Error: fopen\n");
	    exit(1) ;
    }

    while (fgets(buff, MAXLINE, fp) != NULL){
	    if (sscanf(buff, "%d,%s", &lgcode, str) != 2){
	        fprintf(stderr, "Error: sscanf\n");
	        exit(2) ;
	    }
	    printf("%s\n", str) ;
    }

    fclose(fp) ;

    return 0 ;
}
