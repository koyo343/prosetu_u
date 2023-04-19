#include <stdio.h>
#include <stdlib.h>

struct kisyou
{ /* 気温データを管理するレコード */
    int month;
    int day;
    int hour;
    double kion;
};

/* 実験のため配列のサイズを少し小さく */
#define ARRAYSIZE 1000

int readfile(char filename[], struct kisyou kisyoudata[])
{
    FILE *fp;
    int size;
    int month, day, hour;
    double data;
    char file[100];

    /* ファイルのオープン：ファイル名 filename と入力用の利用 "r" を指定 */
    if ((fp = fopen(filename, "r")) == NULL)
    {
        /* 以下の２行はファイルがオープンできなかった時の処理 */
        fprintf(stderr, "Error: File Open\n");
        exit(1); /* プログラムをここで終了させる */
    }

    size = 0;
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF)
    {
        if (size >= ARRAYSIZE)
        {
            fprintf(stderr, "Error: 配列の容量が不足しています。\n");
            exit(2);
        }
        /* すべてのデータを構造体のメンバに保存 */
        kisyoudata[size].month = month;
        kisyoudata[size].day = day;
        kisyoudata[size].hour = hour;
        kisyoudata[size].kion = data;
        (size)++;
    }

    fclose(fp);

    return size;
}

int main(void)
{
    struct kisyou kisyoudata[ARRAYSIZE]; /* 構造体の配列を追加 */
    char filename[100];
    int size, i;

    /* プロンプトの出力とファイル名の入力 */
    fprintf(stderr, "データファイル名：");
    scanf("%s", filename); /* 端末からファイル名を入力 */

    size = readfile(filename, kisyoudata);

    for (i = 0; i < size; i++)
    {
        printf("%d月%d日%d時 %.1f\n", /* 構造体のメンバを出力 */
               kisyoudata[i].month, kisyoudata[i].day,
               kisyoudata[i].hour, kisyoudata[i].kion);
    }

    return 0;
}