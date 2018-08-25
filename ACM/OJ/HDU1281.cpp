#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
const int MAXN = 105; 
int g[MAXN][MAXN];
int uN,vN;
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
    int v;
    for(v=1;v<=vN;v++)
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
    int res=0,u;
    memset(linker,-1,sizeof(linker));
    for(u=1;u<=uN;u++){
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    }  
    return res;  
}  
int main(){
    int K,x,y;
    int i,j;
    int ans;
    int iCase=0;
    while(scanf("%d%d%d",&uN,&vN,&K)!=EOF){
        iCase++;
        memset(g,0,sizeof(g));
        while(K--){
            scanf("%d%d",&x,&y);
            g[x][y]=1;
        }  
        ans=hungary();
        int cnt=0;
        for(i=1;i<=uN;i++)
           for(j=1;j<=vN;j++){
                if(g[i][j]==1){
                   	g[i][j]=0;
                   	if(ans>hungary())
				   		cnt++;
                   	g[i][j]=1;
            	}
            }
        printf("Board %d have %d important blanks for %d chessmen.\n",iCase,cnt,ans);     
    } 
    return 0;   
}
