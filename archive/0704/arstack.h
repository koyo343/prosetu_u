#include "rational.h"

#define	TRUE 1
#define FALSE 0

#define MAXRASTACK 100

/* スタックの利用者は、この構造体の中身を直接操作してはならない */
typedef struct stack {
    RATIONAL data[MAXRASTACK] ;
    int index ;
} RASTACK ;

RASTACK *newRAStack(void) ;
void rastackPush(RASTACK *sp, RATIONAL v) ;
RATIONAL rastackPop(RASTACK *sp) ;
int rastackElement(RASTACK *sp) ;
int rastackIsEmpty(RASTACK *sp) ;
int rastackIsFull(RASTACK *sp) ;