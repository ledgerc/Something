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
#include<stack>
#include<cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

struct node{
	int v,cost;
	node *next;
}edge[maxn<<1],*head[maxn];
int ptr,pos[maxn][maxn],vis[maxn],dist[maxn];
int n,e,sx,ex;
double dp[maxn][maxn];
queue<int> q;
void addedge(int u,int v){
	edge[ptr].v=v;
	edge[ptr].next=head[u];
	edge[ptr].cost=1;
	head[u]=&edge[ptr++];
}
void spfa(int s){
	int u,v;
	node *p;
	while(!q.empty())
		q.pop();
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	for(p=head[s]; p!=NULL; p=p->next){
		v=p->v;
		pos[s][v]=v;
		q.push(v);
		dist[v]=1;
		vis[v]=1;
	}
	while(!q.empty()){
		u=q.front(); vis[u]=0; q.pop();
		for(p=head[u]; p!=NULL; p=p->next){
			v=p->v;
			if(dist[u]+p->cost<dist[v]){
                dist[v]=dist[u]+p->cost;
                pos[s][v]=pos[s][u];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
            else if(dist[u]+p->cost==dist[v]&&pos[s][u]<pos[s][v]){
                pos[s][v]=pos[s][u];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
		}
	}
}
void dfs(int u,int v){
	if(dp[u][v]>=0)
		return ;
	int np,cnt=0;
	double sum=0;
	node *p;
	np=pos[pos[u][v]][v];
	if(np==v){
		dp[u][v]=1;
		return ;
	}
	for(p=head[v];p!=NULL;p=p->next){
        dfs(np,p->v);
        sum+=dp[np][p->v];
        cnt++;
    }
    dfs(np,v);
    sum+=dp[np][v];
    dp[u][v]=sum/(cnt+1)+1;
}
int main(){
    int i,j,a,b;

    while(~scanf("%d%d",&n,&e)){
        scanf("%d%d",&sx,&ex);
        ptr=0;
        memset(head,0,sizeof head);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            dp[i][j]=-1;
        for(i=0;i<e;i++){
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        for(i=1;i<=n;i++){
            dp[i][i]=0;
            pos[i][i]=i;
            spfa(i);
        }
        dfs(sx,ex);
        printf("%.3lf\n",dp[sx][ex]);
    }
    return 0;
}
