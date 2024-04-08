#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXLINE	200
#define	MAXZIPSTR	8
#define	MAXPREFNAME	20
#define MAXPREFNUM	100

struct pref_stat{
    char pref_name[MAXPREFNAME] ;
    int jinkou ;
    int setai ;
    int menseki ;
    int kyojyu_menseki ;
};

#define	NOT_FOUND	-1
int stat_search(struct pref_stat data[], int size, char prefname[]) ;
void stat_pref_add(struct pref_stat data[], int pos, char prefname[]) ;
void stat_pref_update(struct pref_stat data[], int pos, int jinkou, int setai, int menseki, int kyojyu_menseki) ;
void stat_pref_print(struct pref_stat data[], int size) ;

int main(void){
    FILE *fp ;
    char buff[MAXLINE] ;
    char prefname[MAXPREFNAME] ;
    int jinkou, setai, menseki, kyojyu_menseki ;
    struct pref_stat stat_data[MAXPREFNUM] ;
    int index, prefcount ;

    if ((fp = fopen("STAT.csv", "r")) == NULL){
	    fprintf(stderr, "Error: File Open\n");
	    exit(1);
    }

    prefcount = 0 ;
    while (fgets(buff, MAXLINE, fp) != NULL){
	    sscanf(buff, "%*d,%[^,],%*[^,],%d,%d,%d,%d", prefname,
		    &jinkou, &setai, &menseki, &kyojyu_menseki); /* エラー処理を省略 */

	/* 都道府県の添字を取得：なければ追加 */
	    if ((index = stat_search(stat_data, prefcount, prefname)) == NOT_FOUND){
	        stat_pref_add(stat_data, prefcount, prefname);
	        index = prefcount ; /* 登録した都道府県の添字を設定 */
	        prefcount++ ; /* 登録都道府県数の更新 */
	    }

	/* 都道府県ごとの統計値の更新 */ 
	    stat_pref_update(stat_data, index, jinkou, setai, menseki, kyojyu_menseki);
    }

    fclose(fp) ;

    stat_pref_print(stat_data, prefcount) ;

    return 0 ;
}

/* 都道府県の検索 */
int stat_search(struct pref_stat data[], int size, char prefname[]){
    int i ;

    for (i = 0; i < size; i++){
	    if (strcmp(prefname, data[i].pref_name) == 0){
	        return i ;
	    }
    }

    return NOT_FOUND ; /* 見つからない */
}

/* 都道府県の新規登録 */
void stat_pref_add(struct pref_stat data[], int pos, char prefname[]){
    strcpy(data[pos].pref_name, prefname) ; /* 都道府県名の登録 */
    data[pos].jinkou = 0;
    data[pos].setai = 0;
    data[pos].menseki = 0;
    data[pos].kyojyu_menseki = 0;
}

/* 都道府県の統計値の更新 */
void stat_pref_update(struct pref_stat data[], int pos, int jinkou, int setai, int menseki, int kyojyu_menseki){
    data[pos].jinkou += jinkou;
    data[pos].setai += setai;
    data[pos].menseki += menseki;
    data[pos].kyojyu_menseki += kyojyu_menseki;
}

/* 都道府県名と統計値を表示 */
void stat_pref_print(struct pref_stat data[], int size){
    int i ;

    for (i = 0; i < size; i++) {
	    printf("%s: %d, %d, %d, %d\n", data[i].pref_name, data[i].jinkou, data[i].setai, data[i].menseki, data[i].kyojyu_menseki) ;
    }
}
