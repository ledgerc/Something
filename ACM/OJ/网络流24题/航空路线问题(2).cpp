#include<iostream>
#include<map>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<set>
#include<string.h>
#include<string>
#include<vector>
#define MX 1111
#define INF 0x3f3f3f3f
#define mem(x,y) memset(x,y,sizeof(x))
#define FIN freopen("input.txt","r",stdin)
using namespace std;
int n,m,k;
int s,t;
int head[MX],rear;
struct Edge
{
    int nxt,to,cap,cost;
} edge[MX*11];
void edge_init()
{
    mem(head,-1);
    rear=0;
}
void edge_add(int a,int b,int cap,int cost)
{
    //cout<<a<<" "<<b<<endl;
    edge[rear].cost=cost;
    edge[rear].cap=cap;
    edge[rear].nxt=head[a];
    edge[rear].to=b;
    head[a]=rear++;
}
int dis[MX],pre[MX]; //储存前驱顶点
bool vis[MX];
bool spfa(int s, int t)
{
    mem(dis,0x3f);
    mem(vis,0);
    mem(pre,-1);
    deque<int>q;
    q.push_back(s);
    dis[s]=0,vis[s]=1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        vis[u] = 0;
        for (int i= head[u]; ~i; i=edge[i].nxt)
        {
            int v=edge[i].to;
            if (edge[i].cap&& dis[v]>dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                pre[v] = i;
                if (!vis[v])
                {
                    vis[v]=1;
                    if(!q.empty()&&dis[v]<=dis[q.front()])q.push_front(v);//SLF优化
                    else q.push_back(v);
                }
            }
        }
    }
    if (pre[t]==-1) return 0;
    else return 1;
}
//返回的是最大流， cost存的是最小费用
int MCMF(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while (spfa(s, t))
    {

        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
            if (Min > edge[i].cap) Min = edge[i].cap;
        for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
            edge[i].cap -= Min,edge[i ^ 1].cap += Min;
        cost += dis[t]* Min;
        flow+=Min;
    }
    return flow;
}
string ss[111];
void dfs(int u,vector<int> &ans)
{
    u=u-n;
    ans.push_back(u);
    for(int i=head[u]; ~i; i=edge[i].nxt)
    {
        int v=edge[i].to;
    	printf("%d\n",v);
        if(edge[i].cap)
        {
            dfs(v,ans);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        map<string,int> stoi;
        edge_init();
        s=1,t=2*n;
        for(int i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            stoi[s]=i;
            ss[i]=s;
        }
        edge_add(1,1+n,2,-1),edge_add(1+n,1,0,1);
        edge_add(n,n+n,2,-1),edge_add(n+n,n,0,1);
        for(int i=2; i<=n-1; i++)
			edge_add(i,i+n,1,-1),edge_add(i+n,i,0,1);
        for(int i=1; i<=m; i++){
            string aa,bb;
            cin>>aa>>bb;
            int a=stoi[aa],b=stoi[bb];
            if(a>b)
				swap(a,b);
            edge_add(n+a,b,1,0);
            edge_add(b,n+a,0,0);
        }
        int cost,f;
        f=MCMF(s,t,cost);
        cost=-cost;
        cout<<f<<" "<<cost<<endl;
        if(f==2){
            if(cost!=2){
                printf("%d\n",cost-2);
                //cout<<-cost<<endl;
                vector<int> ans;
                dfs(t,ans);
                int w;
                for(int i=0; i<ans.size(); i++) if(ans[i]==s)
                    {
                        w=i;
                        break;
                    }

                for(int i=ans.size()-1; i>=w+1; i--) cout<<ss[ans[i]]<<endl;
                for(int i=0; i<=w; i++) cout<<ss[ans[i]]<<endl;
            }
            else  cout<<2<<endl<<ss[1]<<endl<<ss[n]<<endl<<ss[1]<<endl;

        }
        else puts("No Solution!");
    }
    return 0;
}

