#define	MAXWORDSIZE	100

typedef struct wordcount {
    char word[MAXWORDSIZE] ;
    int count ;
} WORDCOUNT ;

void wordcountInit(void) ; /* 初期化 */
WORDCOUNT *wordcountSearch(char *word) ; /* 単語の検索 */
void wordcountRegister(char *word) ; /* 単語の登録 */
WORDCOUNT *wordcountGetFirst(void) ; /* 最初の単語のデータを取得 */
WORDCOUNT *wordcountGetNext(void) ; /* 次の単語のデータを取得 */

/* 上記のインターフェースが返すWORDCOUNT *に対する操作関数 */
char *wcGetWord(WORDCOUNT *wcp) ; /* WORDCOUNTから単語を取得 */
int wcGetCount(WORDCOUNT *wcp) ; /* WORDCOUNTから単語の出現回数を取得 */
