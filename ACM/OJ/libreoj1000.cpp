#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

#define Max 4000090
#define Mod 998244353

void read (int &now)
{
    now = 0;
    register char word = getchar ();
    while (word < '0' || word > '9')
        word = getchar ();
    while (word >= '0' && word <= '9')
    {
        now = now * 10 + word - '0';
        word = getchar ();
    }
}

int N, M;
int father[Max];

int Find (int x)
{
    return father[x] == x ? x : father[x] = Find (father[x]);
}

inline void Merge (int x, int y)
{
    int now_1 = Find (x);
    int now_2 = Find (y);
    
    if (x != y)
        father[x] = y;
    return ;
}

inline int Query (int x, int y)
{
    return Find (x) == Find (y);
}

int number[Max];

int main (int argc, char *argv[])
{
    read (N);
    read (M);
    
    int x, y, type;
    register int cur = 0;
    for (register int i = 1; i <= N; i ++)
        father[i] = i;
        
    long long Answer = 0;
    for (; M --; )
    {
        read (type);
        read (x);
        read (y);
        x ++;
        y ++;
        if (type == 0)
            Merge (x, y);
        else
            Answer = ((Answer << 1) + Query (x, y)) % Mod;
    }

    
    printf ("%lld", Answer);
    return 0;
}
