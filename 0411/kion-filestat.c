#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10000
void kion_print(double kion[], int size){
    int i;
    for (i = 0; i < size; i++){
	printf("kion[%d]: %.1f\n", i, kion[i]);
    }
}

double kion_heikin(double array[], int size){
    int i ;
    double sum = 0.0 ;
    for (i = 0; i < size; i++) {
	sum += array[i] ;
    }
    return sum/size ;
}

double kion_max(double array[], int size){
    int i;
    double vmax = array[0];
    for (i = 1; i < size; i++){
	if (array[i] > vmax)
	    vmax = array[i];
    }
    return vmax ;
}

double kion_min(double array[], int size){
    int i ;
    double vmin = array[0] ;

    for (i = 1; i < size; i++) {
	if (array[i] < vmin)
	    vmin = array[i] ;
    }
    return vmin ;
}

int main(void){
    FILE *fp;
    int month, day, hour;
    double data;
    double kion[ARRAYSIZE];
    int size;
    int i;

    if ((fp = fopen("kion-20180401.csv", "r")) == NULL){
	fprintf(stderr, "Error: File Open\n");
	exit(1);
    }

    size = 0;
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
	kion[size] = data;
	size++;
    }

    fclose(fp);

    kion_print(kion, ARRAYSIZE) ;
     printf("-----\n") ;
    printf("平均気温: %.1f\n", kion_heikin(kion, ARRAYSIZE));
    printf("最高気温: %.1f\n", kion_max(kion, ARRAYSIZE));
    printf("最低気温: %.1f\n", kion_min(kion, ARRAYSIZE));
    return 0;
}
