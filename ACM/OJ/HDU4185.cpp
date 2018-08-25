#include<stdio.h>
#include<string.h>
const int MAXN=1000;
char map[610][610];
int tt[610][610];
int uN,vN;  //u,vÊýÄ¿
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=0;v<vN;v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }    
        }  
    return false;  
}    
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    } 
    return res;   
}  

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    int iCase=0;
    int tmp;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
       
        tmp=0;
        for(int i=0;i<n;i++)
        {
          scanf("%s",&map[i]);
          for(int j=0;j<n;j++)
           if(map[i][j]=='#') tt[i][j]=tmp++;
        }    
        memset(g,0,sizeof(g));
        uN=vN=tmp;
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
          {
              if(map[i][j]!='#') continue;
              if(i>0&&map[i-1][j]=='#') g[tt[i][j]][tt[i-1][j]]=1;
              if(i<n-1&&map[i+1][j]=='#') g[tt[i][j]][tt[i+1][j]]=1;
              if(j>0&&map[i][j-1]=='#') g[tt[i][j]][tt[i][j-1]]=1;
              if(j<n-1&&map[i][j+1]=='#') g[tt[i][j]][tt[i][j+1]]=1;
          }     
        
        int res=hungary();
        printf("Case %d: %d\n",iCase,res/2);
    }    
    return 0;
}
