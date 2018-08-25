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
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);
/*
10. ?餐巾计划问题
最小费用流, 拆点, 决策分析

一个餐厅在连续的N天中, 每天需要使用的餐巾个数不尽相同. 餐厅每天有三种决策:

买一块新餐巾, 代价p
旧餐巾送到快洗店, m天后使用, 代价f
旧餐巾送到慢洗店, n天后使用, 代价s

设计一个计划使得总花费最小.

构造网络G, 每天对应图G的两个顶点Xi和Yi.Xi表示干净, Yi表示脏.

顶点Xi和Xi+1连一条容量为∞, 费用为0的边, 表示保留旧餐巾的决策.
当i+m?N时, 顶点Xi和Yi+m连一条容量为∞, 费用为f的边, 表示快洗决策.
当i+n?N时, 顶点Xi和Yi+m连一条容量为∞, 费用为s的边, 表示慢洗决策.

另外增加源s和汇t, 以及附加顶点k

从s向每个顶点Xi连一条边, 容量为第i天餐巾需求量ri, 费用0.
从每个顶点Xi向k连边 容量∞费用为0  从附加顶点k向每个顶点Yi连一条容量为∞, 费用为p, 表示购买决策.
从顶点Yi向t连一条容量为ri, 费用为0.

求网络G的最小网络流.
*/
struct Edge{
	int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
int dis[maxn];//double???
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
int main(){
	freopen("in.txt","r",stdin);
	int n,P,M,F,N,S; scanf("%d%d%d%d%d%d",&n,&P,&M,&F,&N,&S);
	init(2*n+4);
	int s=0,t=2*n+1,k=2*n+2;
	for(int i=1; i<=n; i++){
		int tmp; scanf("%d",&tmp);
		addedge(s,i,tmp,0);
		addedge(i+n,t,tmp,0);
	}
	for(int i=1; i<n; i++)
		addedge(i,i+1,inf,0);
	for(int i=1; i<=n; i++)
		if(i+M<=n)
			addedge(i,n+M+i,inf,F);
	for(int i=1; i<=n; i++)
		if(i+N<=n)
			addedge(i,n+N+i,inf,S);
	for(int i=1; i<=n; i++){
		addedge(i,k,inf,0);
		addedge(k,n+i,inf,P);
	}
	int cost; int flow=MincostMaxflow(s,t,cost);
	cout<<cost<<endl; 
}
