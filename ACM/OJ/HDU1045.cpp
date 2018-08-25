#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int uN,vN;
int g[20][20];
int linker[20];
bool used[20];
char map[5][5];
int mapr[5][5];
int mapl[5][5];
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
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=1;u<=uN;u++){
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    }   
    return res; 
}  
int main(){
    int i,j,n;
    while(scanf("%d",&n),n){
        memset(mapl,0,sizeof(mapl));
        memset(mapr,0,sizeof(mapr));
        memset(g,0,sizeof(g));
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++){
               cin>>map[i][j];
               if(map[i][j]=='X')
                  mapl[i][j]=mapr[i][j]=-1;
           }  
           int p1=0;
           uN=0;vN=0;
           for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                  	while(mapr[i][j]==-1&&j<=n)
                 	    j++;
                	p1++;
                	while(mapr[i][j]!=-1&&j<=n){
                      	mapr[i][j]=p1;
                      	if(uN<p1)  uN=p1;
                      	j++;
                }    
            } 
          	int p2=0;
          	for(j=1;j<=n;j++)
             	for(i=1;i<=n;i++){
                 while(mapl[i][j]==-1&&i<=n)
                      i++;
                  p2++;
                  while(mapl[i][j]!=-1&&i<=n)
                  {
                      mapl[i][j]=p2;
                      if(vN<p2)  vN=p2;
                      i++;
                  }    
             }
         for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(mapr[i][j]!=-1&&mapl[i][j]!=-1)
                  g[mapr[i][j]][mapl[i][j]]=1;
            }
         printf("%d\n",hungary());            
    } 
    return 0;   
}
