#define	MAXWORDSIZE	100

/* wordcountの利用者は、この構造体の中身を直接操作してはならない */
typedef struct wordcount {
    char word[MAXWORDSIZE] ;
    int count ;
} WORDCOUNT ;

void wordcountInit(void) ; /* 初期化 */
WORDCOUNT *wordcountSearch(char *word) ; /* 単語の検索 */
void wordcountRegister(char *word) ; /* 単語の登録 */
void wordcountStatistics(void) ; /* すべての単語と出現回数の表示 */