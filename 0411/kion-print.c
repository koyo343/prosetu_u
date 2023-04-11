#include <stdio.h>
#define ARRAYSIZE 24
int main (){
    double data[ARRAYSIZE]={12.8,12.0,11.4,11.2,10.6,10.6,10.3,10.6,13.1,16.9,20.1,22.2,21.9,22.5,23.9,
24.1,22.9,21.9,20.1,18.9,17.6,17.0,16.4,15.7};
    for(int i = 0; i <= ARRAYSIZE; i++){
        printf("%d時:%lf/n", i,data[i]);
    }
    return 0;
}