#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int month, day, hour;
    double data;

    if ((fp = fopen("kion-20180401.csv", "r")) == NULL){
	fprintf(stderr, "Error: File Open\n");
	exit(1);
    }

    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF){
	printf("%d月%d日%d時 %.1f\n", month, day, hour, data);
    }
    fclose(fp);
    return 0;
}
