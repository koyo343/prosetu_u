#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define HASH_TABLE_SIZE 4441
//#define HASH_TABLE_SIZE 6781

typedef struct wordcountlist {
    struct wordcountlist *next ; /* 衝突解消に連鎖法を利用 */
    WORDCOUNT info ;
} WORDCOUNTLIST ;

WORDCOUNTLIST *HashTable[HASH_TABLE_SIZE] ;

int WordNum ;
int TotalWordCount ; /* ファイル中のすべての単語数 */
long CompareCount ; /* 検索のための単語の比較回数 */

void wordcountInit(void)
{
    int i ;

    /* ハッシュ表の初期化 */
    for (i = 0; i < HASH_TABLE_SIZE; i++)
	HashTable[i] = NULL ;

    WordNum = 0 ;
    TotalWordCount = 0 ;
    CompareCount = 0 ;
}

unsigned int hash(char *s)
{
    unsigned int v ;

    /* 単語のすべての文字コードを利用したハッシュ値の計算 */
    for (v = 0; *s != '\0'; s++)
	v = (v << 2) + *s ;

    return v % HASH_TABLE_SIZE ;
}

/* 単語の検索 */
WORDCOUNT *wordcountSearch(char *word)
{
    unsigned int hash_value ;
    WORDCOUNTLIST *wcl ;

    TotalWordCount++ ;

    hash_value = hash(word) ;
  
    if (HashTable[hash_value] != NULL) { /* 既に記録がある */
	for (wcl = HashTable[hash_value]; wcl != NULL; wcl = wcl->next) { /* 単語の検索 */
	    CompareCount++ ;
	    if (strcmp(word, wcl->info.word) == 0) {
		return &(wcl->info) ;/* 単語が既に記録されていたら検索を終了 */
	    }
	}
    }

    return NULL ;
}

/* 単語の登録 */
void wordcountRegister(char *word)
{
    WORDCOUNT *id ;
    WORDCOUNTLIST *wcl ;
    unsigned int hash_value ;

    if ((id = wordcountSearch(word)) != NULL) {
	/* 単語が見つかったら出現回数を更新 */
	id->count++ ;
    } else {
	/* 単語が見つからなければ新規登録 */
	/* ノードの取得 */
	wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST)) ;

	/* ノードへのデータの書き込み */
	strcpy(wcl->info.word, word) ;
	wcl->info.count = 1 ;

	/* ノードの挿入 */
	hash_value = hash(word) ;
	wcl->next = HashTable[hash_value] ;
	HashTable[hash_value] = wcl ;

	WordNum++ ;
    }
}

/* すべての単語と出現回数の表示 */
void wordcountStatistics(void)
{
    int i, in_use ;
    WORDCOUNTLIST *wcl ;

    for (i = 0, in_use = 0; i < HASH_TABLE_SIZE; i++) {
	/* 記録されている単語を表示 */
	if (HashTable[i] != NULL) {
	    in_use++ ;
	    for (wcl = HashTable[i]; wcl != NULL; wcl = wcl->next) {
		printf("%5d: %s\n", wcl->info.count, wcl->info.word) ;
	    }
	}
    }

    fprintf(stderr, "Uniq Word: %d\n", WordNum) ;
    fprintf(stderr, "TotalWordCount: %d\n", TotalWordCount) ;
    fprintf(stderr, "CompareCount: %ld\n", CompareCount) ;
    fprintf(stderr, "Compare/TotalWord: %.1f\n", (double)CompareCount/TotalWordCount) ;
    fprintf(stderr, "TableSize: %d\n", HASH_TABLE_SIZE) ;
    fprintf(stderr, "TableInUse: %d\n", in_use) ;
    fprintf(stderr, "TableUsageRate: %d%%\n",  in_use * 100 / HASH_TABLE_SIZE) ;
}
