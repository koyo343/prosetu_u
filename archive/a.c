#include <stdlib.h>
#include "liststack1.h"

STACK *newStack(void)
{
    STACK *sp ;

    sp = (STACK *)malloc(sizeof(STACK)) ;
    sp->root = NULL ; /* 最初はノードなし */
    sp->num = 0 ; /* 最初はノード数は０ */

    return sp ;
}

void stackPush(STACK *sp, int v)
{
    NODE *np ;

    /* ノードの確保と値の設定 */
    np = (NODE *)malloc(sizeof(NODE)) ;
    np->value = v ;

    /* ノードの挿入 */
    np->next = sp->root ;
    sp->root = np ;

    sp->num++ ; /* ノード数の加算 */
}

int stackPop(STACK *sp)
{
    int v ;
    NODE *np ;

    /* ノードの除去 */
    np = sp->root ;
    sp->root = np->next ;

    v = np->value ; /* ノードの開放前に値を確保 */
    free(np) ; /* ノードの開放 */

    sp->num-- ; /* ノード数の減算 */

    return v ;
}

int stackElement(STACK *sp)
{
    return sp->num ; /* 記録されているデータ数を返す */
}

int stackIsEmpty(STACK *sp)
{
    if (sp->root == NULL)
        return TRUE ;
    else
        return FALSE ;
}

int stackIsFull(STACK *sp)
{
    return FALSE ; /* あふれることはない */
}