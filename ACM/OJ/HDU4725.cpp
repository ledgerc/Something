#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 200005
#define INF 0x3f3f3f3f
using namespace std;

int n,m,c,ans,cnt;
bool vis[maxn],vv[maxn];
int dist[maxn],pp[maxn],lay[maxn];
struct node
{
    int pos,dd;
    bool operator <(const node&xx)const
    {
        return dd>xx.dd;
    }
}cur,now;
struct Node
{
    int v,w;
    int next;
} edge[20*maxn];
priority_queue<node>q;

void init()
{
    memset(pp,0,sizeof(pp));
    memset(vv,0,sizeof(vv));
    memset(dist,0x3f,sizeof(dist));
}
void addedge(int u,int v,int w)
{
    cnt++;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=pp[u];
    pp[u]=cnt;
}
void Dijkstra()
{
    int i,j,u,v,w;
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    dist[1]=0;
    cur.pos=1,cur.dd=0;
    q.push(cur);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        u=now.pos;
        if(vis[u]) continue ;
        vis[u]=1;
        for(i=pp[u]; i; i=edge[i].next)
        {
            v=edge[i].v;
            w=edge[i].w;
            if(!vis[v]&&dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                cur.pos=v,cur.dd=dist[v];
                q.push(cur);
            }
        }
    }
}
int main()
{
    int i,j,t,u,v,w,test=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&c);
        init();
        cnt=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&u);
            lay[i]=u;
            vv[u]=1;
        }
        for(i=1; i<n; i++)
        {
            if(vv[i]&&vv[i+1])
            {
                addedge(n+i,n+i+1,c);
                addedge(n+i+1,n+i,c);
            }
        }
        for(i=1; i<=n; i++)
        {
            addedge(n+lay[i],i,0);
            if(lay[i]>1) addedge(i,n+lay[i]-1,c);
            if(lay[i]<n) addedge(i,n+lay[i]+1,c);
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        Dijkstra();
        printf("Case #%d: ",++test);
        ans=dist[n];
        if(ans<INF) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
