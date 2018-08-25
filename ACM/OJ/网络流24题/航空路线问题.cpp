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
typedef pair<int,int> P;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2+7;
const int maxm = 1e3+7;
const double pi = acos(-1.0);

int n,m; 
//最小费用最大流，求最大费用只需要取相反数，结果取相反数即可。
//点的总数为 N，点的编号 0~N-1
struct Edge{
	int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn],dis[maxn];
bool vis[maxn];
int N;//节点总个数，节点编号从0~N-1 
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
	for(int i=0; i<N; i++){
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
//返回的是最大流，cost存的是最小费
int minCostMaxflow(int s,int t,int &cost){
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
map<string,int> mp;
map<int,string> mp2;
vector<int> ans;
void dfs(int u){
	u=u-n;
	ans.push_back(u);
	for(int i=head[u]; i!=-1; i=edge[i].next){
		int v=edge[i].to;
		if(edge[i].cap)
			dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int s=1,t=2*n; init(2*n+1);
	for(int i=1; i<=n; i++){
		string tmp; cin>>tmp;
		mp[tmp]=i; mp2[i]=tmp;
	}
	addedge(1,n+1,2,-1);
	addedge(n,n+n,2,-1);
	for(int i=2; i<=n; i++)
		addedge(i,n+i,1,-1);
	addedge(n,n+n,2,1);
	for(int i=1; i<=m; i++){
		string tmpu,tmpv; cin>>tmpu>>tmpv;
		int u=mp[tmpu],v=mp[tmpv];
		if(u>v) swap(u,v);
		addedge(u+n,v,1,0);
	}
	int cost; int flow = minCostMaxflow(s,t,cost); cost=-cost;
	pr(flow) prln(cost)
	if(flow==2){
		if(cost!=2){
			printf("%d\n",cost-2);
			dfs(t); int tmp;
			for(int i=0; i<ans.size(); i++)
				if(ans[i]==s){
					tmp=i;break;
				}
			for(int i=ans.size()-1; i>=tmp+1; i--)
				cout<<mp2[ans[i]]<<"\n";
			for(int i=tmp; i>=0; i--)
				cout<<mp2[ans[i]]<<"\n";
		}
		else
			cout<<2<<"\n"<<mp2[1]<<"\n"<<mp2[n]<<"\n"<<mp2[1]<<"\n";
	}
	else
		puts("No Solution!\n");
	return 0;
} 
