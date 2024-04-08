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

int WordNum ;
int TotalWordCount ; /* ファイル中のすべての単語数 */
long CompareCount ; /* 検索のための単語の比較回数 */

/* 初期化 */
void wordcountInit(void)
{
    root = NULL ;

    WordNum = 0 ;
    TotalWordCount = 0 ;
    CompareCount = 0 ;
}

/* 単語の検索 */
WORDCOUNT *wordcountSearch(char *word)
{
    WORDCOUNTLIST *wcl ;

    TotalWordCount++ ;

    for (wcl = root; wcl != NULL; wcl = wcl->next) {
	CompareCount++ ;
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

	WordNum++ ;
    }
}

/* すべての単語と出現回数の表示 */
void wordcountStatistics(void)
{
    WORDCOUNTLIST *wcl ;

    for (wcl = root; wcl != NULL; wcl = wcl->next) {
	printf("%5d: %s\n", wcl->info.count, wcl->info.word) ;
    }

    fprintf(stderr, "Uniq Word: %d\n", WordNum) ;
    fprintf(stderr, "TotalWordCount: %d\n", TotalWordCount) ;
    fprintf(stderr, "CompareCount: %ld\n", CompareCount) ;
    fprintf(stderr, "Compare/TotalWord: %.1f\n", (double)CompareCount/TotalWordCount) ;
}
