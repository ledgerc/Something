#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<bitset>
#include<stack>
#include<cctype>
#define sc(x) scanf("%d",&x);
#define pr(x) cout<<#x<<": "<<x<<" ";
#define prln(x) cout<<#x<<": "<<x<<endl;
#define bug() cout<<"bug: "<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e4+7;
const double pi = acos(-1.0);


struct Edge{
	int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
int dis[maxn];
bool vis[maxn];
int N;
void init(int n){
	N=n;
	tol=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v,int cap,int cost){
	edge[tol].to=v; edge[tol].cap=cap; edge[tol].cost=cost; edge[tol].flow=0;
	edge[tol].next=head[u]; head[u]=tol++;
	edge[tol].to=u;	edge[tol].cap=0; edge[tol].cost=-cost;	edge[tol].flow=0;
	edge[tol].next=head[v];	head[v]=tol++;
}
bool spfa(int s,int t){
	queue<int> q;
	for(int i=0; i<=N; i++){
		dis[i]=inf;
		vis[i]=false;
		pre[i]=-1;
	}
	dis[s]=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=false;
		for(int i=head[u]; i!=-1; i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
				dis[v]=dis[u]+edge[i].cost;
				pre[v]=i;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			} 
		}
	}
	if(pre[t]==-1)
		return false;
	else
		return true;
}
//返回的是最大流，cost存的是最小费
int MincostMaxflow(int s,int t,int &cost){
	int flow=0;
	cost=0;
	while(spfa(s,t)){
		int Min=inf;
		for(int i=pre[t]; i!=-1; i=pre[edge[i^1].to]){
		 	if(Min>edge[i].cap-edge[i].flow)
				Min=edge[i].cap-edge[i].flow;
		}
		for(int i=pre[t]; i!=-1; i=pre[edge[i^1].to]){
			edge[i].flow+=Min;
			edge[i^1].flow-=Min;
			cost+=edge[i].cost*Min;
		}
		flow+=Min;
	}
	return flow;
}
int a[maxn],b[maxn],g[maxn][maxn];
int main(){
	freopen("in.txt","r",stdin);
	int n,m,s,t; scanf("%d%d",&n,&m);
	s=0; t=m+n+1;
	init(t+1);
	for(int i=1; i<=n; i++){
		int tmp; scanf("%d",&tmp);
		a[i]=tmp;
		addedge(s,i,tmp,0);
	}
	for(int i=1; i<=m; i++){
		int tmp; scanf("%d",&tmp);
		b[i]=tmp;
		addedge(n+i,t,tmp,0);
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			int tmp; scanf("%d",&tmp);
			g[i][j]=tmp;
			addedge(i,n+j,inf,tmp);
		}
	int cost1; MincostMaxflow(s,t,cost1);
	init(t+1);
	for(int i=1; i<=n; i++){
		addedge(s,i,a[i],0);
	}
	for(int i=1; i<=m; i++){
		addedge(n+i,t,b[i],0);
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			addedge(i,n+j,inf,-g[i][j]);
		}
	int cost2; MincostMaxflow(s,t,cost2);
	cout<<cost1<<"\n"<<-cost2<<endl;
	return 0;
}
