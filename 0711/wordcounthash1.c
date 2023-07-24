#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define HASH_TABLE_SIZE 4441

typedef struct wordcountlist
{
    struct wordcountlist *next;
    WORDCOUNT info;
} WORDCOUNTLIST;

WORDCOUNTLIST *HashTable[HASH_TABLE_SIZE];

void wordcountInit(void)
{
    int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++)
        HashTable[i] = NULL;
}

unsigned int hash(char *s)
{
    unsigned int v;
    for (v = 0; *s != '\0'; s++)
        v = (v << 2) + *s;
    return v % HASH_TABLE_SIZE;
}

WORDCOUNT *wordcountSearch(char *word)
{
    unsigned int hashvalue;
    WORDCOUNTLIST *wcl;

    hashvalue = hash(word);

    for (wcl = HashTable[hashvalue]; wcl != NULL; wcl = wcl->next)
    {
        if (strcmp(wcl->info.word, word) == 0)
            return &(wcl->info);
    }

    return NULL;
}

void wordcountRegister(char *word)
{
    WORDCOUNT *id;
    WORDCOUNTLIST *wcl;
    unsigned int hashvalue;

    if ((id = wordcountSearch(word)) != NULL)
    {
        id->count++;
    }
    else
    {
        wcl = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST));

        strcpy(wcl->info.word, word);
        wcl->info.count = 1;

        hashvalue = hash(word);
        wcl->next = HashTable[hashvalue];
        HashTable[hashvalue] = wcl;
    }
}

void wordcountStatistics(void)
{
    int i;
    WORDCOUNTLIST *wcl;

    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        for (wcl = HashTable[i]; wcl != NULL; wcl = wcl->next)
        {
            printf("Word: %s, Count: %d\n", wcl->info.word, wcl->info.count);
        }
    }
}