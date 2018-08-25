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
const int maxm = 1e6+7;
const double pi = acos(-1.0);


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
struct Node{
	int l,r;
}a[maxn];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> vec; map<int,int> mp;
	for(int i=1; i<=n; i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		if(a[i].l>a[i].r) swap(a[i].l,a[i].r);
		vec.push_back(a[i].l); vec.push_back(a[i].r);
	}
	sort(vec.begin(),vec.end()); vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int m=vec.size(); int s=m,t=m+1; init(t+1);
	addedge(s,0,k,0); addedge(m-1,t,k,0);
	for(int i=0; i<m; i++){
		mp[vec[i]]=i;
		if(i+1<m){
			addedge(i,i+1,inf,0);
		}
	}
	ll res=0;
	for(int i=1; i<=n; i++){
		addedge(mp[a[i].l],mp[a[i].r],1,a[i].l-a[i].r);
	}
	int cost; int flow=MincostMaxflow(s,t,cost);
	cout<<-cost<<endl;
	return 0;
}
