#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 3010
#define inf 0x7fffffff
using namespace std;
struct node
{
    int next,to,s;
};
node Edge[N<<1];
int n,m,tot=1,T;
int head[N];
int h[N];
int qq[N];
bool vis[N];

void add(int x,int y,int z)
{
    Edge[++tot].next=head[x];
    Edge[tot].to=y;
    Edge[tot].s=z;
    head[x]=tot;
}

void ins(int x,int y,int z)
{
    add(x,y,z),add(y,x,0);
}

bool bfs()
{
    queue<int>Q;
    Q.push(0);
    memset(h,-1,sizeof(h));
    memset(vis,0,sizeof(vis));
    h[0]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=head[u];i;i=Edge[i].next)
        {
            int to=Edge[i].to,s=Edge[i].s;
            if(!s||h[to]!=-1)continue;
            h[to]=h[u]+1;
            vis[to]=true;
            Q.push(to);
        }
    }
    if(h[T]==-1)return false;
    return true;
}

int dfs(int u,int f)
{
    if(u==T)return f;
    int used=0;
    for(int i=head[u];i;i=Edge[i].next)
    {
        int to=Edge[i].to,s=Edge[i].s;
        if(!s||h[to]!=h[u]+1)continue;
        int w=f-used;
        w=dfs(to,min(w,s));
        used+=w;
        Edge[i].s-=w;
        Edge[i^1].s+=w;
        if(used==f)return f;
    }
    if(!used)h[u]=-1;
    return used;
}

int dinic()
{
    int ans=0;
    while(bfs())
        ans+=dfs(0,inf);
    return ans;
}

void getans()
{
    int cnt=0;
    for(int i=1;i<=n;i++)if(vis[i])qq[++cnt]=i;
    for(int i=1;i<cnt;i++)printf("%d ",qq[i]);
    printf("%d\n",qq[cnt]);
    memset(qq,0,sizeof(qq));
    cnt=0;
    for(int i=1;i<=m;i++)if(vis[i+n])qq[++cnt]=i;
    for(int i=1;i<cnt;i++)printf("%d ",qq[i]);
    printf("%d\n",qq[cnt]);
}

int main()
{
    cin>>n>>m;
    T=n+m+1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        ins(0,i,x);
        char ch=getchar();
        while((ch=getchar())!='\n')
        {
            x=ch-'0';
            while((ch=getchar())&&ch>='0'&&ch<='9')
                x=x*10+ch-'0';
            ins(i,x+n,inf);
            if(ch=='\n')break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        ins(i+n,T,x);
    }
    int tmp=dinic();
    getans();
    cout<<sum-tmp<<endl;
    return 0;
}
