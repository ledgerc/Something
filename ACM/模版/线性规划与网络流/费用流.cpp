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
const double eps = 1e-8;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);


int n,a[maxn][maxn],b[maxn][maxn];
struct Edge{
	int to,next,cap,flow;
	double cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn];
double dis[maxn];
bool vis[maxn];
int N;
void init(int n){
	N=n;
	tol=0;
	memset(head,-1,sizeof head);
}
void addedge(int u,int v,int cap,double cost){
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
	dis[s]=0; vis[s]=true;
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
int MincostMaxflow(int s,int t,double &cost){
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
		//	pr(edge[i].cost) prln(Min)
		}
		flow+=Min;
	}
	return flow;
}
bool check(double mid){
	init(2*n+2);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			addedge(i,n+j,1,-(double)(a[i][j]-1.0*mid*b[i][j]));
		}
	for(int i=1; i<=n; i++)
		addedge(0,i,1,0);
	for(int i=1; i<=n; i++)
		addedge(i+n,2*n+1,1,0);
	double cost=0; int flow=MincostMaxflow(0,2*n+1,cost); cost=-cost;
	return cost-eps>0;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&b[i][j]);
	double l=0,r=10000.0;
	while(r-l>=eps){
		double mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%.6f\n",l);
}
