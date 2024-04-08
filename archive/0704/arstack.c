#include <stdlib.h>
#include "arstack.h"

RASTACK *newRAStack(void)
{
    RASTACK *sp ;

    sp = (RASTACK *)malloc(sizeof(RASTACK)) ;
    sp->index = 0 ;

    return sp ;
}

void rastackPush(RASTACK *sp, RATIONAL v)
{
    sp->data[sp->index++] = v ;
}

RATIONAL rastackPop(RASTACK *sp)
{
    return sp->data[--sp->index] ;
}

int rastackElement(RASTACK *sp)
{
    return sp->index ;
}

int rastackIsEmpty(RASTACK *sp)
{
    if (sp->index <= 0)
        return TRUE ;
    else
        return FALSE ;
}

int rastackIsFull(RASTACK *sp)
{
    if (sp->index >= MAXRASTACK)
        return TRUE ;
    else
        return FALSE ;
}