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
#define sc(x) scanf("%d",&x);
#define PR(x) cout<<#x<<": "<<x<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const double eps = 1e-4;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+7;
const int maxm = 1e6+7;
const double pi = acos(-1.0);

int n,m;
int tot,tol;
struct Edge{
	int u,v,w;
}edge[maxn*2];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void add_edge(int u,int v,int w){
	edge[tot].u=u; edge[tot].v=v; edge[tot].w=w; tot++;
}

struct Edge2{
	int to,cost,next;
}edge2[maxn];
int head[maxn];
void addedge(int u,int v,int w){
	edge2[tol].to=v;
	edge2[tol].cost=w;
	edge2[tol].next=head[u];
	head[u]=tol++;
}

int f[maxn];
int find(int x){
	if(f[x]==-1)
		return x;
	return f[x]=find(x);
}
void init(){
	tot=tol=0;
	memset(f,-1,sizeof f);
	memset(head,-1,sizeof head);
}
void Kruskal(){
	sort(edge,edge+m,cmp);
	int cnt=0;
	tot=0;
	for(int i=0; i<m; i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(find(u)!=find(v)){
			addedge(u,v,w);
			addedge(v,u,w);
			f[find(u)]=find(v);
			cnt++;
		}
		if(cnt==n-1)
			return ;
	}
}

ll ans[maxn];
int ee[maxn];
int down[maxn];
void dfs(int u,int pre){
	down[u]=1;
	for(int i=head[u]; i!=-1; i=edge2[i].next){
		int v=edge2[i].to;
		if(v==pre)
			continue;
		ee[v]=edge2[i].cost;
		dfs(v,u);
		down[u]+=down[v];
	}
}
int main(){
	scanf("%d%d",&n,&m); int u,v,w;
	init();
	for(int i=0; i<m; i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	Kruskal();
	dfs(1,1);
	ll last=0;
	int index=0;
	for(int i=1; i<=n; i++)
		if(ee[i]!=-1)
			ans[ee[i]]+=1ll*down[i]*(n-down[i]);
	for(int i=0; i<maxm; i++){
		ans[i]+=last;
		last=ans[i]/2;
		ans[i]%=2;
		if(ans[i]!=0)
			index=i;
	}
	for(int i=index; i>=0; i--)
		cout<<ans[i];
	cout<<endl;
	
	
	return 0;
}
