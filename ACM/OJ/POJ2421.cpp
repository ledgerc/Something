#include <cstdio>    
#include <algorithm>    
#include <iostream>    
#include <cstring>    
#include <cmath>    
#include <cstdlib>    
#include <string>    
#include <map>    
#include <vector>    
#include <set>    
#include <queue>    
#include <stack>    
#include <cctype>    
using namespace std;    
  
#define input freopen("input.txt","r",stdin)  
#define output freopen("output.txt","w",stdout)  
#define For1(i,a,b) for (i=a;i<b;i++)  
#define For2(i,a,b) for (i=a;i<=b;i++)  
#define Dec(i,a,b) for (i=a;i>b;i--)  
#define Dec2(i,a,b) for (i=a;i>=b;i--)  
#define Fill(x,a) memset(x,a,sizeof(x))  
#define inf 1<<30  
  
const int maxn=1000;  
const int maxm=500000;  
int F[maxn];  
int cnt;  
struct Edge  
{  
    int u,v,w;  
}edge[maxm];  
  
  
int tol;  
int Map[maxn][maxn];  
  
void addedge(int u,int v,int w)  
{  
    edge[tol].u=u;  
    edge[tol].v=v;  
    edge[tol++].w=w;  
}  
  
bool cmp(Edge a,Edge b)  
{  
    return a.w<b.w;  
}  
  
int find(int x)  
{  
    if (F[x]==-1) return x;  
    return F[x]=find(F[x]);  
}  
  
int Kruskal(int n)  
{  
    sort(edge,edge+tol,cmp);  
    int ans=0;  
    for(int i=0;i<tol;i++)  
    {  
        int u=edge[i].u;  
        int v=edge[i].v;  
        int w=edge[i].w;  
        int t1=find(u);  
        int t2=find(v);  
        if (t1!=t2)  
        {  
            ans+=w;  
            F[t1]=t2;  
            cnt++;  
        }  
        if (cnt==n-1) break;  
    }  
    if (cnt<n-1) return 0;  
    return ans;  
}  
  
int main()  
{
    int i,n,m,x,y,z,ans,t,j,k;  
    while(cin>>n)  
    {  
        cnt=ans=tol=0;  
        Fill(Map,0);  
        Fill(F,-1);  
        For2(i,1,n)For2(j,1,n)scanf("%d",&Map[i][j]);  
        For2(i,1,n-1)  
            For2(j,i+1,n)  
            {  
                addedge(i,j,Map[i][j]);  
                //addedge(j,i,Map[i][j]);  
            }  
        cin>>m;  
        For2(i,1,m)  
        {  
            scanf("%d%d",&x,&y);  
            int u=find(x);  
            int v=find(y);  
            if (u!=v)  
            {  
                F[u]=v;  
                cnt++;  
            }  
            //F[x]=y;  
        }  
        ans=Kruskal(n);  
        cout<<ans<<endl;  
    }  
    return 0;  
} 
