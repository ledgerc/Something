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
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 5e2+7;
const int maxm = 2000010;
const double pi = acos(-1.0);

char s[maxm],t[65];  
bitset<maxn> w[maxn],P[2];  
int main(){
    while(gets(s+1)){  
        int n;scanf("%d",&n);  
        for(int i=0;i<256;i++)
			w[i].reset();
        for(int i=1;i<=n;i++){
            int len; scanf("%d%s",&len,t+1);
            for (int j=1; j<=len; j++)
				w[t[j]].set(i);
        }
        int now=0; bool flag=false;
        P[now].reset();P[now][0]=1;	
        int len=strlen(s+1);
        for (int i=1; i<=len; i++){
            P[!now]=(P[now]<<1)&w[s[i]];
            now^=1; P[now][0]=1;
            if(P[now][n]){
                flag=true;
				printf("%d\n",i-n+1);
            }
        }
        if(!flag)
			printf("NULL\n");
		getchar();
    }
    return 0;
}
