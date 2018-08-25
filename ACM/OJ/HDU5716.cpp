#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bitset>
using namespace std;
const int M = 500+5;
const int N = 2000000+5;
const int SIZE = 64;
const int MAGIC = 128;
char txt[N];
int id[MAGIC];
bitset<M> dp[2];
bitset<M> mt[MAGIC];
int n, m;

inline void output(bitset<M>& bt){
    for (int i=0; i<=m; i++)
        printf("\t #  %4d %4d\n", i, bt[i]?1:0);
    puts("");
}

int main(){
    int cnt = 0;
    for (int i='0'; i<='9'; i++) id[i] = ++ cnt;
    for (int i='A'; i<='Z'; i++) id[i] = ++ cnt;
    for (int i='a'; i<='z'; i++) id[i] = ++ cnt;

    while (gets(txt+1)){
        n = strlen(txt+1);
        scanf("%d", &m);
        int l; char s[SIZE];
        for (int i=1; i<=cnt; i++) mt[i].reset();
        for (int i=1; i<=m; i++){
            scanf("%d %s", &l, s);
            for (int j=0; j<l; j++){
                int x = id[s[j]];
                mt[x].set(i);
            }
        }

        int cur = 0;
        dp[cur].reset();
        dp[cur].set(0);
        bool flag = 0;
        for (int i=1; i<=n; i++){
            int x = id[txt[i]];
            cur ^= 1;
            dp[cur] = dp[cur^1] << 1 & mt[x];
            dp[cur].set(0);
            if (dp[cur][m]){
                flag = 1;
                printf("%d\n", i - m + 1);
            }
        }
        if (!flag) puts("NULL");
        getchar();
    }
    return 0;
}
