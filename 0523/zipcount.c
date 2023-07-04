#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXLINE	200
#define	MAXPREFNAME	20
#define MAXPREFNUM	100

struct pref_zip_count{
    char pref_name[MAXPREFNAME] ;
    int zipcount ;
} ;

#define	NOT_FOUND	-1
int zip_pref_search(struct pref_zip_count data[], int size, char prefname[]) ;
void zip_pref_add(struct pref_zip_count data[], int pos, char prefname[]) ;
void zip_pref_print(struct pref_zip_count data[], int size) ;

int main(void){
    FILE *fp ;
    char buff[MAXLINE] ;
    char prefname[MAXPREFNAME] ;
    struct pref_zip_count zip_count[MAXPREFNUM] ;
    int index, prefcount ;

    if ((fp = fopen("YUBIN.csv", "r")) == NULL){
        fprintf(stderr, "Error: File Open\n") ;
        exit(1) ;
    }

    prefcount = 0 ;
    while (fgets(buff, MAXLINE, fp) != NULL){
	/* 最初の2つのデータは読み飛ばす。エラーチェックを省略 */
	    sscanf(buff, "%*d,%*[^,],%[^,]", prefname) ;

	/* 都道府県名の検索とデータの更新、あるいは新規登録 */
	    if ((index = zip_pref_search(zip_count, prefcount, prefname)) != NOT_FOUND){
	    /* 既に記録されていたら件数をインクリメント */
	        zip_count[index].zipcount++ ;
	    } else {
	    /* まだ登録されていなければ都道府県を追加 */
	        zip_pref_add(zip_count, prefcount, prefname) ;
	        prefcount++ ; /* 登録されている都道府県数を更新 */
	    }
    }

    fclose(fp) ;

    zip_pref_print(zip_count, prefcount) ;

    return 0 ;
}

/* 都道府県名が配列に既に登録されていればその添え字を返す */
int zip_pref_search(struct pref_zip_count data[], int size, char prefname[]){
    int i ;

    for (i = 0; i < size; i++) { /* 都道府県名の検索 */
	    if (strcmp(prefname, data[i].pref_name) == 0){
	        return i ;
	    }
    }

    return NOT_FOUND ; /* 見つからない */
}

/* 都道府県名を配列に登録する */
void zip_pref_add(struct pref_zip_count data[], int pos, char prefname[]){
    strcpy(data[pos].pref_name, prefname) ; /* 都道府県名の登録 */
    data[pos].zipcount = 1 ; /* 郵便番号数の初期化 */
}

/* 配列に記録されている郵便番号数と都道府県名の組を出力する */
void zip_pref_print(struct pref_zip_count data[], int size){
    int i, prefcount ;

    for (i = 0; i < size; i++){ /* 郵便番号数と都道府県名を表示 */
	    printf("%d: %s\n", data[i].zipcount, data[i].pref_name) ;
    }
}
