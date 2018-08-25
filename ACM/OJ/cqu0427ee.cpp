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
const int maxn = 2e5+7;
const int maxm = 6e5+7;
const double pi = acos(-1.0);

int n,m;
struct Edge{
	int u,v,w;
}edge[maxm];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
struct Edge2{
	int to,next,cost;
}e[maxm];
int tot,tol;
int head[maxn],f[maxn];
void init(){
	memset(f,-1,sizeof f);
	memset(head,-1,sizeof head);
	tot=tol=0;
}
void addkedge(int u,int v,int w){
	edge[tot].u=u; edge[tot].v=v; edge[tot].w=w; tot++;
}
void addedge(int u,int v,int w){
	e[tol].to=v; e[tol].cost=w; e[tol].next=head[u]; head[u]=tol++;
}
int find(int x){
	if(f[x]==-1)
		return x;
	return f[x]=find(f[x]);
}
void Kruskal(int n){
	sort(edge,edge+tot,cmp);
	int cnt=0;
	for(int i=0; i<tot; i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int tmp1=find(u),tmp2=find(v);
		if(tmp1!=tmp2){
			addedge(u,v,w); addedge(v,u,w);
			f[tmp1]=tmp2;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
}

int ee[maxn];
int down[maxn],up[maxn];
void dfs(int u,int pre){
	down[u]=1;
	for(int i=head[u]; i!=-1; i=e[i].next){
		int v=e[i].to;
		if(v==pre)
			continue;
		ee[v]=e[i].cost;
		dfs(v,u);
		down[u]+=down[v];
	}
	up[u]=n-down[u];
}

int main(){
	cin>>n>>m;
	init();
	while(m--){
		int u,v,w; cin>>u>>v>>w;
		addkedge(u,v,w);
	}
	Kruskal(n);
	ee[1]=-1;
	dfs(1,1);
	ll tmp[maxm];
	memset(tmp,0,sizeof tmp);
	for(int i=1; i<=n; i++)
		if(ee[i]!=-1)
			tmp[ee[i]]+=1ll*up[i]*down[i];
	ll tnt=0;
	int index=0;
	for(int i=0; i<maxm; i++){
		tmp[i]+=tnt;
		tnt=tmp[i]/2;
		tmp[i]%=2;
		if(tmp[i]!=0)
			index=i;
	}
	for(int i=index; i>=0; i--)
		cout<<tmp[i];
	cout<<endl;
}
