#include <stdio.h>
#include "arstack.h"

int main(void)
{
    RASTACK *sp ;

    sp = newRAStack() ;

    printf("Element %d\n", rastackElement(sp)) ; 
    rastackPush(sp, newRational(1,2)) ;
    rastackPush(sp, newRational(1,3)) ;
    rastackPush(sp, newRational(1,4)) ;
    rastackPush(sp, newRational(1,5)) ;

    printf("Element %d\n", rastackElement(sp)) ;

    while (!rastackIsEmpty(sp))
        raPrintNl(rastackPop(sp)) ;

    printf("Element %d\n", rastackElement(sp)) ;

    return 0 ;
}