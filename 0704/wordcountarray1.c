#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define MAXWORD	10000

/* WORDCOUNTを配列を利用して複数記録できるようにする */
WORDCOUNT WordCount[MAXWORD] ;
int WordNum ; /* 記録されている単語の数 */
int WordCurrent ; /* 次に取り出すWORDCOUNTのインデックス */

/* 初期化 */
void wordcountInit(void)
{
    WordNum = 0 ;
}

/* 単語の検索 */
WORDCOUNT *wordcountSearch(char *word)
{
    int i ;

    for (i = 0; i < WordNum; i++) {
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

/* 最初の単語のデータを取得 */
WORDCOUNT *wordcountGetFirst(void)
{
    WordCurrent = 0 ;

    if (WordCurrent < WordNum)
	return &WordCount[WordCurrent++] ;
    else
	return NULL ;
}

/* 次の単語のデータを取得 */
WORDCOUNT *wordcountGetNext(void)
{
    if (WordCurrent < WordNum)
	return &WordCount[WordCurrent++] ;
    else
	return NULL ;
}

/* WORDCOUNTから単語を取得 */
char *wcGetWord(WORDCOUNT *wcp)
{
    return wcp->word ;
}

/* WORDCOUNTから単語の出現回数を取得 */
int wcGetCount(WORDCOUNT *wcp)
{
    return wcp->count ;
}
