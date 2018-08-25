#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define MOD 1000000007
const int INF=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;
int n,m,tt;
const int MAXN = 510;
int a[10000],b[10000];
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
    for(int v = 0; v < vN;v++)
    if(g[u][v] && !used[v]){
        used[v] = true;
        if(linker[v] == -1 || dfs(linker[v])){
            linker[v] = u;
            return true;
        }
    }
    return false;
}
int hungary(){
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 0;u < uN;u++){
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}
int main(){
    int i,j,k;
    while(scanf("%d",&n)!=EOF){
        uN=vN=n;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);
        int ans=hungary();
        if(ans<n){
            printf("-1\n");
            continue;
        }
        int res=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(linker[j]==i){
					break;
				}
            }
            if(i!=j){
                a[res]=i,b[res++]=j;
                int temp=linker[j];
                linker[j]=linker[i];
                linker[i]=temp;
            }
        }
        printf("%d\n",res);
        for(i=0;i<res;i++)
            printf("C %d %d\n",a[i]+1,b[i]+1);
    }
}
