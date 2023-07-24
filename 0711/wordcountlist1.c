#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

/* WORDCOUNTを連結リストを利用して複数記録できるようにする */
typedef struct wordcountlist {
    struct wordcountlist *next ;
    WORDCOUNT info ; /* 配列版の構造体と共通 */
} WORDCOUNTLIST ;

WORDCOUNTLIST *root ;

/* 初期化 */
void wordcountInit(void)
{
    root = NULL ;
}

/* 単語の検索 */
WORDCOUNT *wordcountSearch(char *word)
{
    WORDCOUNTLIST *wcl ;

    for (wcl = root; wcl != NULL; wcl = wcl->next) {
	/* 単語が既に記録されていたらそのアドレスを返す */
	if (strcmp(word, wcl->info.word) == 0)
	    return &(wcl->info) ;
    }

    return NULL ;
}

/* 単語の登録 */
void wordcountRegister(char *word)
{
    WORDCOUNT *id ;
    WORDCOUNTLIST *wcl ;

    if ((id = wordcountSearch(word)) != NULL) {
	/* 単語が見つかったら出現回数を更新 */
	id->count++ ;
    } else {
	/* 単語が見つからなければ新規登録 */
	wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST)) ;
	strcpy(wcl->info.word, word) ;
	wcl->info.count = 1 ;

	wcl->next = root ;
 	root = wcl ;
    }
}

/* すべての単語と出現回数の表示 */
void wordcountStatistics(void)
{
    WORDCOUNTLIST *wcl ;

    for (wcl = root; wcl != NULL; wcl = wcl->next) {
	printf("%5d: %s\n", wcl->info.count, wcl->info.word) ;
    }
}
