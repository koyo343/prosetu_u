#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	200

int main(void){
    FILE *fp;
    char buff[MAXLINE] ;
    char zipstr[10], prefname[20], cityname[50] ;

    if ((fp = fopen("YUBIN.csv", "r")) == NULL){
	    fprintf(stderr, "Error: fopen\n") ;
	    exit(1) ;
    }

    while (fgets(buff, MAXLINE, fp) != NULL){
	    if (sscanf(buff, "%*d,%[^,],%[^,],%[^,]",zipstr, prefname, cityname) != 3){
	        fprintf(stderr, "Error: sscanf\n") ;
	        exit(2) ;
	    }
	    printf("%s,%s,%s\n", zipstr, prefname, cityname) ;
    }

    fclose(fp) ;

    return 0 ;
}
