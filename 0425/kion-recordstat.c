#include<stdio.h> 
#include<stdlib.h> 
 
/*配列で渡された気温の平均値を求めて返す*/ 
double kionheikin(double array[],int size); 

/*配列で渡された気温の最大値を求めて返す*/ 
double kionmax(double array[],int size); 

/*配列で渡された気温の最小値を求めて返す*/ 
double kionmin(double array[],int size); 


structkisyou{/*気温データを管理するレコード*/ 
int month; 
int day; 
int hour; 
double kion; 
};
/*ファイルの内容を構造体の配列に記録しデータ数を返す*/
int readfile(char filename[],struct kisyouarray[],int amax);

#define MAXFILENAME100 /*ファイル名の最大長*/

/*１年間のデータを読み込めるように*/
#define ARRAYSIZE10000
#define DAYARRAY24

int main(void)
{
    char filename[MAXFILENAME];
    struct kisyoukisyoudata[ARRAYSIZE];/*構造体の配列を追加*/
    double kion[DAYARRAY];
    int size;/*配列に読み込まれたデータ数*/
    int month,day;
    
    /*追加：必要に応じて変数を定義*/
    
    fprintf(stderr,"データファイル名：");
    scanf("%s",filename);/*端末からファイル名を入力*/
    size=readfile(filename,kisyoudata,ARRAYSIZE);
    
    while(1){/*orfor(;;)*/
    fprintf(stderr,"月日：");
    scanf("%d%d",&month,&day);/*端末から月日を入力*/
    
    if(month==0){/*月に0を指定すると終了させる*/
    fprintf(stderr,"検索を終了します。\n");
    break;/*orexit(0)*/
    }
    
    /*追加：月日の指定で得られた２４個の気温をkion[]に転記する*/
    
    /*追加：平均、最高、最低気温を求め指定形式で出力*/
    }
    
    return 0;
    }