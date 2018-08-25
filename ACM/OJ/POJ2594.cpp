#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=510;
int uN,vN;//u,vÊıÄ¿
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
    int v;
    for(v=0;v<vN;v++)
      	if(g[u][v]&&!used[v]){
          	used[v]=true;
          	if(linker[v]==-1||dfs(linker[v])){
              	linker[v]=u;
              	return true;
          	}
    	}
    return false;
}
int hungary(){
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++){
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
void floyed(int n){
    for(int i=0;i<n;i++)
      	for(int j=0;j<n;j++){
          	if(g[i][j]==0){
            	for(int k=0;k<n;k++){
                if(g[i][k]==1&&g[k][j]==1){
                    g[i][j]=1;
                    break;
                }
            }
        }
    }
}
int main(){
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        uN=vN=n;
        memset(g,0,sizeof(g));
        while(m--){
            scanf("%d%d",&u,&v);
            u--;v--;
            g[u][v]=1;
        }
        floyed(n);
        printf("%d\n",n-hungary());
    }
    return 0;
}
