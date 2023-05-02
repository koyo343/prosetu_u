#include<stdio.h>
#include<stdlib.h>

struct kisyou{
    /*気温データを管理するレコード*/
    int month;
    int day;
    int hour;
    double kion;
};
#define DAYARRAY 24

/*HTMLによる気温表の出力*/
void html_report(struct kisyou array[],int size){
    /*記述：kion−html.cのmain関数のHTML出力処理相当*/
}
#define MAXFILENAME 100 /*ファイルの最大長*/

/*1年間のファイルを読み込めるように*/
#define ARRAYSIZE 10000

int main(){
    char filename[MAXFILENAME];
    struct kisyou kisyoudata[ARRAYSIZE]; /*構造体の配列を追加*/
    int size; /*配列に読み込まれたデータ数*/

    fprintf(stderr,"データファイル名");
    scanf("%s",filename); /*端末より、ファイル名を入力*/

    /*データファイルの読み込み*/
    size = readfile(filename,kisyoudata,ARRAYSIZE);
    /*統計データのHTML整形出力*/
    html_report(kisyoudata,size);

    return 0;
}