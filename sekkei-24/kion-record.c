#include <stdio.h>
#include <stdlib.h>

struct kisyou
{ /* 気温データを管理するレコード */
    int month;
    int day;
    int hour;
    double kion;
};

/* ファイルの内容を構造体の配列に記録しデータ数を返す */
int readfile(char filename[], struct kisyou array[], int amax)
{
    FILE *fp;
    int month, day, hour;
    double data;
    int size;

    /* ここからはファイルの入力処理 */
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }

    size = 0; /* 読み込んだデータの格納位置を初期化 */
    /* ファイルの最後 EOF(End of File) までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF)
    {
        if (size >= amax)
        {
            fprintf(stderr, "Error: 配列の容量が不足しています。\n");
            exit(2);
        }
        /* すべてのデータを構造体のメンバに保存 */
        array[size].month = month;
        array[size].day = day;
        array[size].hour = hour;
        array[size].kion = data;
        size++; /* 次に値を格納する位置の添字に更新 */
    }

    fclose(fp);

    return size; /* 読み込んだデータ数を返す */
}

/* 一つにまとめられた構造体データを関数に渡す */
void printrecord(struct kisyou record)
{
    printf("%d月%d日%d時 %.1f\n", /* 構造体のメンバを出力 */
           record.month, record.day, record.hour, record.kion);
}

#define MAXFILENAME 100 /* ファイル名の最大長 */

/* 実験のため配列のサイズを少し小さく */
#define ARRAYSIZE 1000

int main(void)
{
    char filename[MAXFILENAME];
    struct kisyou kisyoudata[ARRAYSIZE]; /* 構造体の配列を追加 */
    int size;                            /* 配列に読み込まれたデータ数 */
    int i;

    fprintf(stderr, "データファイル名：");
    scanf("%s", filename); /* 端末からファイル名を入力 */

    size = readfile(filename, kisyoudata, ARRAYSIZE);

    /* 配列に読み込まれたデータの出力処理 */
    for (i = 0; i < size; i++)
    {
        /* 構造体：単純に１つのレコードを渡す */
        printrecord(kisyoudata[i]);
    }

    return 0;
}