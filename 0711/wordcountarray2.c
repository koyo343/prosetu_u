#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define MAXWORD	30000

/* WORDCOUNTを配列を利用して複数記録できるようにする */
WORDCOUNT WordCount[MAXWORD] ;
int WordNum ;
int TotalWordCount ; /* ファイル中のすべての単語数 */
long CompareCount ; /* 検索のための単語の比較回数 */

/* 初期化 */
void wordcountInit(void)
{
    WordNum = 0 ;
    TotalWordCount = 0 ;
    CompareCount = 0 ;
}

/* 単語の検索 */
WORDCOUNT *wordcountSearch(char *word)
{
    int i ;

    TotalWordCount++ ;

    for (i = 0; i < WordNum; i++) {
	CompareCount++ ;
	/* 単語が既に記録されていたらそのアドレスを返す */
	if (strcmp(word, WordCount[i].word) == 0)
	    return &WordCount[i] ;
    }

    return NULL ;
}

/* 単語の登録 */
void wordcountRegister(char *word)
{
    WORDCOUNT *id ;

    if ((id = wordcountSearch(word)) != NULL) {
	/* 単語が見つかったら出現回数を更新 */
	id->count++ ;
    } else {
	/* 単語が見つからなければ新規登録 */
	if (WordNum >= MAXWORD) {
	    fprintf(stderr, "エラー：単語の登録可能数を超えました\n") ;
	    exit(100) ;
	}

	strcpy(WordCount[WordNum].word, word) ;
	WordCount[WordNum].count = 1 ;
	WordNum++ ;
    }
}

/* すべての単語と出現回数の表示 */
void wordcountStatistics(void)
{
    int i ;

    for (i = 0; i < WordNum; i++) {
	printf("%5d: %s\n", WordCount[i].count, WordCount[i].word) ;
    }

    fprintf(stderr, "Uniq Word: %d\n", WordNum) ;
    fprintf(stderr, "TotalWordCount: %d\n", TotalWordCount) ;
    fprintf(stderr, "CompareCount: %ld\n", CompareCount) ;
    fprintf(stderr, "Compare/TotalWord: %.1f\n", (double)CompareCount/TotalWordCount) ;
}
