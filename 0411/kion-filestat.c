#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10000

double kion_heikin(double array[], int size){
    int i;
    int sum;

    for (i = 0, sum = 0; i < size; i++)
    {
        sum += array[i];
    }

    return (double)sum / size;
}

double kion_max(double array[], int size){
    int i;
    double max = array[0];

    for (i = 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}

double kion_min(double array[], int size){
    int i;
    double min = array[0];

    for (i = 1; i < size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }

    return min;
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
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF){
        kion[size] = data;
        size++;
    }
    fclose(fp);

    for (i = 0; i < size; i++){
        printf("kion[%d]: %.1f\n", i, kion[i]);
    }

    printf("平均: %2.1lf\n", kion_heikin(kion, size));
    printf("最大: %2.1lf\n", kion_max(kion, size));
    printf("最小: %2.1lf\n", kion_min(kion, size));

    return 0;
}