#include <stdio.h>
#include "arraystack.h"
int main(void){
    STACK *sp1,*sp2 ;

    sp1=newStack ( ) ;
    sp2=newStack ( ) ;
    printf("Stack1:Element %d\n",stackElement(sp1));
    stackPush (sp1,1) ;
    stackPush ( sp1 , 2 ) ;
    stackPush ( sp1 , 4 ) ;
    stackPush ( sp1 , 8 ) ;
    printf("Stack2:Element %d\n",stackElement(sp2));
    stackPush ( sp2 , 1 0 0 ) ;
    stackPush ( sp2 , 2 0 0 ) ;
    stackPush ( sp2 , 4 0 0 ) ;
    printf("Stack1:Element %d\n",stackElement(sp1));
    printf("Stack2:Element %d\n",stackElement(sp2));

    while(!stackIsEmpty(sp1))
        printf("Stack1:%d\n",stackPop(sp1));
    while(!stackIsEmpty(sp2))
        printf("Stack2:%d\n",stackPop(sp2));
    printf("Stack1:Element %d\n",stackElement(sp1));
    printf("Stack2:Element %d\n",stackElement(sp2));

    return 0 ;
}